// include 可以导入任何文件，而且不做检查。为了防止代码被重复包含，
// 通常用“#ifndef/#define/#endif”来保护整个头文件。
// 例子
// static uint32_t calc_table[] = { // 非常大的一个数组，有几十行，可以将内容放到一个文件中，用include引进来。
//     0x00000000, 0x77073096, 0xee0e612c, 0x990951ba,
//     0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
//     0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
//     0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91};
// 
// 编译以后，查看test.p文件内容 gcc 2_include.cpp -E > test.p

static uint32_t  calc_table[] = {
#  include "calc_values.inc"        // 非常大的一个数组，细节被隐藏
};