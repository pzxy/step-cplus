#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class Test {
public:
	Test() { cout << "Test的构造函数..." << endl; }
	~Test() { cout << "Test的析构函数..." << endl; }

	int getDebug() { return this->debug; }

private:
	int debug = 20;
};

// 不要定义为全局变量，没有意义
//auto_ptr<Test> test(new Test);

void memoryLeak1() {
	//Test *test = new Test;

	// 定义智能指针
	auto_ptr<Test> test(new Test);
	
	cout << "test->debug：" << test->getDebug() << endl;
	cout << "(*test).debug：" << (*test).getDebug() << endl;


	// get方法
	Test *tmp = test.get();		// 获取指针返回
	cout << "tmp->debug：" << tmp->getDebug() << endl;


	// release方法
	Test *tmp2 = test.release();	// 取消智能指针对动态内存的托管
	delete tmp2;	// 之前分配的内存需要自己手动释放


	// reset方法：重置智能指针托管的内存地址，如果地址不一致，原来的会被析构掉
	test.reset();			// 释放掉智能指针托管的指针内存，并将其置NULL
	test.reset(new Test());	// 释放掉智能指针托管的指针内存，并将参数指针取代之


	// 忠告：不要将智能指针定义为指针
	//auto_ptr<Test> *tp = new auto_ptr<Test>(new Test);

	// 忠告：不要定义指向智能指针对象的指针变量
	//auto_ptr<Test> t1(new Test);
	//auto_ptr<Test> t2(new Test);
	//t1 = t2;

	return;
}

int memoryLeak2() {
	//Test *test = new Test();

	// 定义智能指针
	auto_ptr<Test> test(new Test);

	// ...此处省略一万行代码

	// 发生某些异常，需要结束函数
	if (1) {
		return -1;
	}

	//delete test;
	return 1;
}


int main1(void) {

	//memoryLeak1();

	//memoryLeak2();

	//Test *test = new Test;
	//auto_ptr<Test> test(new Test);

	//cout << "test->debug：" << test->getDebug() << endl;
	//cout << "(*test).debug：" << (*test).getDebug() << endl;


	 auto_ptr 被C++11抛弃的主要原因
	//auto_ptr<string> p1(new string("I'm Li Ming!"));
	//auto_ptr<string> p2(new string("I'm age 22."));
	//
	//cout << "p1：" << p1.get() << endl;
	//cout << "p2：" << p2.get() << endl;

	//p1 = p2;
	//cout << "p1 = p2 赋值后：" << endl;
	//cout << "p1：" << p1.get() << endl;
	//cout << "p2：" << p2.get() << endl;



	// 弊端2.在STL容器中使用auto_ptr存在着重大风险，因为容器内的元素必须支持可复制
	vector<auto_ptr<string>> vec;
	auto_ptr<string> p3(new string("I'm P3"));
	auto_ptr<string> p4(new string("I'm P4"));

	vec.push_back(std::move(p3));
	vec.push_back(std::move(p4));

	cout << "vec.at(0)：" <<  *vec.at(0) << endl;
	cout << "vec[1]：" <<  *vec[1] << endl;


	// 风险来了：
	vec[0] = vec[1];
	cout << "vec.at(0)：" << *vec.at(0) << endl;
	cout << "vec[1]：" << *vec[1] << endl;


	// 弊端3.不支持对象数组的内存管理
	//auto_ptr<int[]> array(new int[5]);	// 不能这样定义
	return 0;
} 