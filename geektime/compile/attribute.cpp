// 属性是用两对方括号的形式“[[…]]，控制编译器的“编译指令”。
[[deprecated("deadline:2023-01-21")]] // C++14 or later
// warning: ‘int old_func()’ is deprecated: deadline:2020-12-31 [-Wdeprecated-declarations]
int old_func();

[[gnu::unused]]      // 声明下面的变量暂不使用，不是错误
int nouse;  

int main(){};

/**
deprecated：与 C++14 相同，但可以用在 C++11 里。
unused：用于变量、类型、函数等，表示虽然暂时不用，但最好保留着，因为将来可能会用。
constructor：函数会在 main() 函数之前执行，效果有点像是全局对象的构造函数。
destructor：函数会在 main() 函数结束之后执行，有点像是全局对象的析构函数。
always_inline：要求编译器强制内联函数，作用比 inline 关键字更强。
hot：标记“热点”函数，要求编译器更积极地优化。
*/