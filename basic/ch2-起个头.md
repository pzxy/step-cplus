# hello world
文件名字 hello.cpp
```c++
#include <iostream>
int main()
{
    using namespace std;
    cout << "Come up and C++ me some time.";
    cout << endl;
    cout << "You won't regret it !" << endl;
}
```
编译 g++ hello.cpp
执行 ./a.out


问： using namespace 编译指令，什么是编译指令？
13/12/2022 22:00 答：遵守C++98规则，命名空间std里面的cout其实就是std::cout，特别是有相同的方法时，可以放在不同的命名空间。using namespace std可以放在函数中，也可放在文件开头。rust中都是包管理的，如果有相同方法在不同包中，那么就是 包名::方法名。其实都差不多，go、java也一样的。

以；结尾的为语句，和rust一样。

问： #include <iostream> ?
13/12/2022 22:02 答：iostream文件中内容会和hello.cpp一同发送给编译器。编译器组合成符合文件，下一阶段使用这个文件。

![ch2.1.png](./image/ch2.1.png)
总结：头文件无论如何c++都能用。优先 新式风格。

换行： `cout << endl`  ，字符串中使用`\n`也可以
读取命令行赋值变量a：`cin >> a`

吐槽：树上说cout比printf()高级，这该死的高级，不能李姐。但是cin挺好用的。

编译报错：报错_函数名比如_sqrt 找不到这个库，编译时加-lm，g++ sqrt.C -lm

```c++
// 变量声明
int a；
a = 1；
int b = 2;
// 函数
void simon(int)
void simon(int n) {
	using namespace std;
	cout << "布洛芬" <<endl;	
} 
// 没有返回值，不能这样用
ss = simon(1)
```

# 总结
cin，cout对象是 istream 和 ostream类的实例