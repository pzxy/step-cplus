# 智能指针

智能指针是行为类似指针的类对象。但这种对象还有其他功能。
智能指针的主要目的是为了解决内存泄漏，如果我们new一个对象却没有delete它，就会发生内存泄漏。
好在class中，我们可以使用析构函数来释放对象过期的内存。智能指针就是通过这个原理来解决指针自动释放的问题。
智能指针常见的有4个，`auto_ptr`(C++11中被摒弃),`unique_ptr`,`shared_ptr`,`weak_ptr`。

1. 用法:
```CPP
#include <memory>
智能指针<类型> 变量名(new 类型)
//auto_ptr<类型> 变量名(new 类型)
```
2. 创建一个Test类
```cpp
class Test {
public:
	Test() { cout << "Test的构造函数..." << endl; }
	~Test() { cout << "Test的析构函数..." << endl; }

	int getDebug() { return this->debug; }

private:
	int debug = 20;
};
```
3. 使用这个类定义智能指针

```CPP
int main(void) {
	//Test *test = new Test;
	auto_ptr<Test> test(new Test);
    // 智能指针可以像普通指针那样使用，因为操作符的重载，这个以后再了解
	cout << "test->debug：" << test->getDebug() << endl;
	cout << "(*test).debug：" << (*test).getDebug() << endl;
	return 0;
} 

/* 可以看到这样的输出：
Test的构造函数...
test->debug：20
(*test).debug：20
Test的析构函数...
/*
```
4. 智能指针常用的三个函数，下面的test是一个智能指针对象。
```cpp
// 1. get() 获取智能指针托管的指针地址
Test *tmp = test.get()
// 2. release() 取消智能指针对动态内存的托管
Test *tmp2 = test.release();	
delete tmp2;	// 之前分配的内存需要自己手动释放
// 3. reset() 重置智能指针托管的内存地址，如果地址不一致，原来的会被析构掉
test.reset();			// 释放掉智能指针托管的指针内存，并将其置NULL
test.reset(new Test());	// 释放掉智能指针托管的指针内存，并将参数指针取代之
```
# auto_ptr

auto_ptr定义了管理指针的对象，可以将new获取的地址赋给这种对象，其析构函数将使用delete来释放内存。虽然auto_ptr已经不用了，但是了解以下还是很有必要的。
 auto_ptr 两个指针不能指向同一个资源，复制或赋值都会改变资源的所有权。
1. auto_ptr使用注意点

```cpp
// 1. 尽可能不要将auto_ptr 变量定义为全局变量或指针；没有意义，全局变量也是一样效果
auto_ptr<Test> *tp = new auto_ptr<Test>(new Test);

// 2. 不要把auto_ptr 智能指针赋值给同类型的另外一个 智能指针；
// p2赋值给p1后，首先p1会先将自己原先托管的指针释放掉，然后接收托管p2所托管的指针，
// 然后p2所托管的指针制NULL，也就是p1托管了p2托管的指针，而p2放弃了托管。
auto_ptr<Test> p1(new Test);
auto_ptr<Test> p2(new Test);
p1 = p2;	

// 3. 不要再容器中使用auto_ptr，风险很大
vector<auto_ptr<string>> vec;
auto_ptr<string> p1(new string("I'm P3"));
auto_ptr<string> p2(new string("I'm P4"));
vec[0] = vec[1];	// 如果进行赋值，问题又回到了上面一个问题中。

// 4. 不支持对对象数组内存管理
auto_ptr<int[]> array(new int[5]);// 错误的定义
```
# unique_ptr 

unique_ptr取代auto_ptr，他解决了auto_ptr 遇到的问题。

unique_ptr使用特点：

```cpp
// 1. 无法进行左值复制赋值操作，但允许临时右值赋值构造和赋值
unique_ptr<string> p1(new string("I'm Li Ming!"));
unique_ptr<string> p2(new string("I'm age 22."));
p1 = p2;					// 禁止左值赋值
unique_ptr<string> p3(p2);	// 禁止左值赋值构造
unique_ptr<string> p3(std::move(p1));	// 使用move把左值转成右值就可以赋值了，效果和auto_ptr赋值一样
p1 = std::move(p2);

// 2. 在 STL 容器中使用unique_ptr，不允许直接赋值
vector<unique_ptr<string>> vec;
unique_ptr<string> p3(new string("I'm P3"));
unique_ptr<string> p4(new string("I'm P4"));
vec.push_back(std::move(p3));
vec.push_back(std::move(p4));
vec[0] = vec[1];	// 不允许直接赋值 
vec[0] = std::move(vec[1]);	// 需要使用move修饰，使得程序员知道后果

// 3. 支持对象数组的内存管理
// 会自动调用delete [] 函数去释放内存
unique_ptr<int[]> array(new int[5]);	// 支持这样定义
```

关于左值和右值:
左值是通过栈可以找到的值，无论这个值是本身保存在栈上，还是栈上只保存了地址而实际数据在堆上。只要通过栈能找到的值就是左值。
右值其实就是现在还是没人要数据，他可能在栈上，堆上或者寄存器上，但是呢，没有一个变量和他绑定，表达式结束后它必须，也一定会被回收掉。

# shared_ptr 
unique_ptr 并不能适应所有情况.

auto_ptr 与 unique_ptr智能指针的陷阱.
```cpp
auto_ptr<string> p1;
string *str = new string("智能指针的内存管理陷阱");
p1.reset(str);	// p1托管str指针
{
	auto_ptr<string> p2;
	p2.reset(str);	// p2接管str指针时，会先取消p1的托管，然后再对str的托管
}

// 此时p1已经没有托管内容指针了，为NULL，在使用它就会内存报错！
cout << "str：" << *p1 << endl;
```

shared_ptr 是通过引用计数来做的，这其实是垃圾回收的一种。
1. 使用例子：
```cpp
shared_ptr<Person> sp1;
shared_ptr<Person> sp2(new Person(2));
// 获取智能指针管控的共享指针的数量	use_count()：引用计数
cout << "sp1	use_count() = " << sp1.use_count() << endl;
// 共享
sp1 = sp2;
shared_ptr<Person> sp3(sp1);
cout << "sp1	use_count() = " << sp1.use_count() << endl;
cout << "sp2	use_count() = " << sp2.use_count() << endl;
cout << "sp2	use_count() = " << sp3.use_count() << endl << endl;
// sp1和sp2和sp3共同托管同一个指针,引用计数都是3.
```
2. 构造方式：
```cpp
// 1. 方式1
shared_ptr<int> up1(new int(10));  // int(10) 的引用计数为1
shared_ptr<int> up2(up1);  // 使用智能指针up1构造up2, 此时int(10) 引用计数为2
// 2. 使用make_shared 初始化对象，分配内存效率更高(推荐使用)，make_shared函数的主要功能是在动态内存中分配一个对象并初始化它，返回指向此对象的shared_ptr; 
shared_ptr<int> up3 = make_shared<int>(2); // 多个参数以逗号','隔开，最多接受十个
shared_ptr<string> up4 = make_shared<string>("字符串");
shared_ptr<Person> up5 = make_shared<Person>(9);
```

3. 赋值
```cpp
shared_ptrr<int> up1(new int(10));  // int(10) 的引用计数为1
shared_ptr<int> up2(new int(11));   // int(11) 的引用计数为1
up1 = up2;	// int(10) 的引用计数减1,计数归零内存释放，up2共享int(11)给up1, int(11)的引用计数为2
```
4. 释放对象
```cpp
shared_ptrr<int> up1(new int(10));
up1 = nullptr ;	// int(10) 的引用计数减1,计数归零内存释放 
// 或
up1 = NULL; // 作用同上 
```
5. 重置和交换
```cpp
p.reset() ; 将p重置为空指针，所管理对象引用计数 减1
p.reset(p1); 将p重置为p1（的值）,p 管控的对象计数减1，p接管对p1指针的管控
p.reset(p1,d); 将p重置为p1（的值），p 管控的对象计数减1并使用d作为删除器
std::swap(p1,p2); // 交换p1 和p2 管理的对象，原对象的引用计数不变
p1.swap(p2);    // 交换p1 和p2 管理的对象，原对象的引用计数不变
```

6. 使用陷阱循环引用问题
Boy类中有Girl的智能指针；Girl类中有Boy的智能指针；当他们交叉互相持有对方的管理对象时。
```cpp
#include <iostream>
#include <string>
#include <memory>
using namespace std;
class Girl;
class Boy {
public:
	Boy() {
		cout << "Boy 构造函数" << endl;
	}
	~Boy() {
		cout << "~Boy 析构函数" << endl;
	}
	void setGirlFriend(shared_ptr<Girl> _girlFriend) {
		this->girlFriend = _girlFriend;
	}
private:
	shared_ptr<Girl> girlFriend;
};

class Girl {
public:
	Girl() {
		cout << "Girl 构造函数" << endl;
	}
	~Girl() {
		cout << "~Girl 析构函数" << endl;
	}
	void setBoyFriend(shared_ptr<Boy> _boyFriend) {
		this->boyFriend = _boyFriend;
	}
private:
	shared_ptr<Boy> boyFriend;
};

void useTrap() {
	shared_ptr<Boy> spBoy(new Boy());
	shared_ptr<Girl> spGirl(new Girl());
	// 陷阱用法,如果注释掉下面任何一行，则就算是单方获得管理对象的共享指针，这样是可以正常释放掉的。
	spBoy->setGirlFriend(spGirl);
	spGirl->setBoyFriend(spBoy);
	// 此时boy和girl的引用计数都是2
}

int main(void) {
	useTrap();
	system("pause");
	return 0;
}
```
当我们执行useTrap函数时，是没有结束此函数，boy和girl指针其实是被两个智能指针托管的，所以他们的引用计数是2
useTrap函数结束后，函数中定义的智能指针被清掉，boy和girl指针的引用计数减1，还剩下1，对象中的智能指针还是托管他们的，所以函数结束后没有将boy和gilr指针释放的原因就是于此。

# weak_ptr
weak_ptr 设计的目的是为配合 shared_ptr 而引入的一种智能指针来协助 shared_ptr 工作, 它只可以从一个 shared_ptr 或另一个 weak_ptr 对象构造, 它的构造和析构不会引起引用记数的增加或减少。同时weak_ptr 没有重载*和->但可以使用 lock 获得一个可用的 shared_ptr 对象。

1. 使用
```cpp
shared_ptr<Boy> spBoy(new Boy());
shared_ptr<Girl> spGirl(new Girl());

// 弱指针的使用
weak_ptr<Girl> wpGirl_1;			// 定义空的弱指针
weak_ptr<Girl> wpGirl_2(spGirl);	// 使用共享指针构造
wpGirl_1 = spGirl;					// 允许共享指针赋值给弱指针

// 弱指针不支持 * 和 -> 对指针的访问
// wpGirl_1->setBoyFriend(spBoy);
// (*wpGirl_1).setBoyFriend(spBoy);

// 在必要的使用可以转换成共享指针
shared_ptr<Girl> sp_girl;
sp_girl = wpGirl_1.lock();
cout << sp_girl.use_count() << endl;
// 使用完之后，再将共享指针置NULL即可
sp_girl = NULL;
```
2. 使用弱指针解决循环引用的问题
在类中使用弱指针接管共享指针，在需要使用时就转换成共享指针去使用即可。
```cpp
#include <iostream>
#include <string>
#include <memory>
using namespace std;
class Girl;
class Boy {
public:
	Boy() {
		cout << "Boy 构造函数" << endl;
	}
	~Boy() {
		cout << "~Boy 析构函数" << endl;
	}
	void setGirlFriend(shared_ptr<Girl> _girlFriend) {
		this->girlFriend = _girlFriend;


		// 在必要的使用可以转换成共享指针
		shared_ptr<Girl> sp_girl;
		sp_girl = this->girlFriend.lock();

		cout << sp_girl.use_count() << endl;
		// 使用完之后，再将共享指针置NULL即可
		sp_girl = NULL;
	}
private:
    // 注意这里是一个 weak_ptr
	weak_ptr<Girl> girlFriend;
};

class Girl {
public:
	Girl() {
		cout << "Girl 构造函数" << endl;
	}
	~Girl() {
		cout << "~Girl 析构函数" << endl;
	}
	void setBoyFriend(shared_ptr<Boy> _boyFriend) {
		this->boyFriend = _boyFriend;
	}
private:
	shared_ptr<Boy> boyFriend;
};

void useTrap() {
	shared_ptr<Boy> spBoy(new Boy());
	shared_ptr<Girl> spGirl(new Girl());
	spBoy->setGirlFriend(spGirl);
	spGirl->setBoyFriend(spBoy);
}

int main(void) {
	useTrap();
	system("pause");
	return 0;
}
```
3. expired 检查指针的合法性
```cpp
std::weak_ptr<int> gw;
...
if (!gw.expired()) {
	std::cout << "gw is valid\n";	// 有效的，还有托管的指针
} else {
	std::cout << "gw is expired\n";	// 过期的，没有托管的指针
}
```

# 总结

1. 不要把一个原生指针给多个智能指针管理;

```cpp
int *x = new int(10);
unique_ptr< int > up1(x);
unique_ptr< int > up2(x);
// 或者
up1.reset(x);
up2.reset(x);
```

2. 一定要使用u.release()的返回值
在调用u.release()时是不会释放u所指的内存的，这时返回值就是对这块内存的唯一索引，如果没有使用这个返回值释放内存或是保存起来，这块内存就泄漏了.

3. 禁止delete 智能指针get 函数返回的指针
如果我们主动释放掉get 函数获得的指针，那么智能 指针内部的指针就变成野指针了，析构时造成重复释放。


4. 不要使用指针的get()去初始化另外一个指针
```cpp
shared_ptr< int > sp4(sp1.get());
```