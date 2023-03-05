# CMake generated Testfile for 
# Source directory: /Users/pzxy/Workspace/C++/cplus_step/cmake/demo8
# Build directory: /Users/pzxy/Workspace/C++/cplus_step/cmake/demo8
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_run "demo" "5" "2")
set_tests_properties(test_run PROPERTIES  _BACKTRACE_TRIPLES "/Users/pzxy/Workspace/C++/cplus_step/cmake/demo8/CMakeLists.txt;44;add_test;/Users/pzxy/Workspace/C++/cplus_step/cmake/demo8/CMakeLists.txt;0;")
add_test(test_usage "demo")
set_tests_properties(test_usage PROPERTIES  PASS_REGULAR_EXPRESSION "Usage: .* base exponent" _BACKTRACE_TRIPLES "/Users/pzxy/Workspace/C++/cplus_step/cmake/demo8/CMakeLists.txt;47;add_test;/Users/pzxy/Workspace/C++/cplus_step/cmake/demo8/CMakeLists.txt;0;")
add_test(test_5_2 "demo" "5" "2")
set_tests_properties(test_5_2 PROPERTIES  PASS_REGULAR_EXPRESSION "is 25" _BACKTRACE_TRIPLES "/Users/pzxy/Workspace/C++/cplus_step/cmake/demo8/CMakeLists.txt;53;add_test;/Users/pzxy/Workspace/C++/cplus_step/cmake/demo8/CMakeLists.txt;59;do_test;/Users/pzxy/Workspace/C++/cplus_step/cmake/demo8/CMakeLists.txt;0;")
add_test(test_10_5 "demo" "10" "5")
set_tests_properties(test_10_5 PROPERTIES  PASS_REGULAR_EXPRESSION "is 100000" _BACKTRACE_TRIPLES "/Users/pzxy/Workspace/C++/cplus_step/cmake/demo8/CMakeLists.txt;53;add_test;/Users/pzxy/Workspace/C++/cplus_step/cmake/demo8/CMakeLists.txt;60;do_test;/Users/pzxy/Workspace/C++/cplus_step/cmake/demo8/CMakeLists.txt;0;")
add_test(test_2_10 "demo" "2" "10")
set_tests_properties(test_2_10 PROPERTIES  PASS_REGULAR_EXPRESSION "is 1024" _BACKTRACE_TRIPLES "/Users/pzxy/Workspace/C++/cplus_step/cmake/demo8/CMakeLists.txt;53;add_test;/Users/pzxy/Workspace/C++/cplus_step/cmake/demo8/CMakeLists.txt;61;do_test;/Users/pzxy/Workspace/C++/cplus_step/cmake/demo8/CMakeLists.txt;0;")
