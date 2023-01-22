// 动态断言: assert 虽然是一个宏，但在预处理阶段不生效，而是在运行阶段才起作用，所以又叫“动态断言”
// assert(i > 0 && "i must be greater than zero");
// assert(p != nullptr);
// assert(!str.empty());

// 静态断言：叫“static_assert”，不过它是一个专门的关键字，而不是宏。因为它只在编译时生效，运行阶段看不见，所以是“静态”的。


// 用静态断言来保证模板参数必须大于等于零
template <int N>
struct fib
{
    static_assert(N >= 0, "N >= 0");

    static const int value =
        fib<N - 1>::value + fib<N - 2>::value;
};

// 保证我们的程序只在 64 位系统上运行，可以用静态断言在编译阶段检查 long 的大小，必须是 8 个字节
static_assert(
  sizeof(long) >= 8, "must run on x64");
  
static_assert(
  sizeof(int)  == 4, "int must be 32bit");

// static_assert 运行在编译阶段，只能看到编译时的常数和类型，看不到运行时的变量、指针、内存数据等

char* p = nullptr;
static_assert(p == nullptr, "some error.");  // 错误用法