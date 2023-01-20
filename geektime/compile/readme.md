# 命令
```bash
# 1. 生成动态文件
gcc test_a.c test_b.c test_c.c -fPIC -shared -o libtest.so
# 或者
g++ test_a.c test_b.c test_c.c -fPIC -shared -o libtest2.so
# 2. 链接使用
gcc test.c -L. -ltest -o test
或者
g++ test.c -L. -ltest2 -o test2
# 3. 执行./test
# 4. 然后修改test_x.c任何一个文件，然后执行第一步，然后执行./test，但是无需执行第二步。
```

```text
-shared该选项指定生成动态连接库（让连接器生成T类型的导出符号表，有时候也生成弱连接W类型的导出符号），不用该标志外部程序无法连接。相当于一个可执行文件

-fPIC：表示编译为位置独立的代码，不用此选项的话编译后的代码是位置相关的所以动态载入时是通过代码拷贝的方式来满足不同进程的需要，而不能达到真正代码段共享的目的。

-L.：表示要连接的库在当前目录中

-ltest：编译器查找动态连接库时有隐含的命名规则，即在给出的名字前面加上lib，后面加上.so来确定库的名称

LD_LIBRARY_PATH：这个环境变量指示动态连接器可以装载动态库的路径。
当然如果有root权限的话，可以修改/etc/ld.so.conf文件，然后调用 /sbin/ldconfig来达到同样的目的，不过如果没有root权限，那么只能采用输出LD_LIBRARY_PATH的方法了。
```