aux_source_directory(. sub_lib_dir)
# dd_library 将 sub_lib_dir 中的源文件编译为静态链接库。
add_library(MathFunctions ${sub_lib_dir})
