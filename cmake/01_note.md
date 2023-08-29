# 如何引入第三方包总结

## 方式一：源码引入
一般项目都提供了可以将项目打包成`a.h`和`a.cc`的方式，我们将这两个文件引入到我们的项目中。
当作我们项目中的一个模块，然后正常的编译。
此方式需要注意的是，三方库编译的需要一些依赖库需要我们自己在cmake文件中导入。
一般常见的库cmake中都自带了，比如需要`OpenSSL`,则通过`find_package(OpenSSL REQUIRED)`来导入这些库。

## 方式二：安装到操作系统默认依赖库中
一般三方库提供了操作步骤，可以编译移动到系统默认的lib库中。
有的库操作完后会有`xxx.h`和`xxx.a`文件。
有的没有`xxx.a`文件，而是将代码的定义和实现都放到了`xxx.h`，然后提示我们通过`find_package()`来导入这个库。

导入以后，再使用 `include_directories(SYSTEM /usr/local/include)` 导入后，我们再文件中就可以直接通过`<xxx.h>`引入来使用了。

## 方式三：将三方库作为我们项目自己的submodule
我们创建一个模块，专门为了存放三方包，比如是`third_party`, 进入这个目录，然后通过`git submodule add -f git@github.com:xxxx.git`的方式，
将三方包下载下来。`git submodule update --init --recursive`来更新库最新代码,然后`third_party`是作为我们项目的子目录存在的，当我们执行`cmake`命令的时候,
会这里的cmake文件，我们通过`execute_process()`来执行我们的自己的命令。

主要思路是：将三方库编译，然后将编译后的`xxx.a`文件复制到我们项目的依赖库中。这里主要麻烦的地方在于编译，
因为每个库的包管理工具不同的，有的是cmake，有的是meson。无论如何，我们的目的就是通过`execute_process()`命令
来执行编译，然后将编译出来的文件复制到项目的lib库中。最后再将`include_directories(SYSTEM third_party)`.
这样我们就可以直接引用三方项目文件了。


以上方法根据实际情况来做。
自己写一些小的demo，推荐方式二。
项目安全性要求比较高，推荐方式一。
大型项目开发，推荐方式三。

还需要注意的是，优先使用系统自带的lib库，因为很多lib库系统就自带了。如果自己还去维护，麻烦还容易出错。
