# CMake generated Testfile for 
# Source directory: /home/abduljf/Desktop/Local Repo/C Test Project/Memory_Pool/Memory_Pool
# Build directory: /home/abduljf/Desktop/Local Repo/C Test Project/Memory_Pool/Memory_Pool/cmake_build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[apool]=] "/home/abduljf/Desktop/Local Repo/C Test Project/Memory_Pool/Memory_Pool/binary/tests-out/allocate_pool_test")
set_tests_properties([=[apool]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/abduljf/Desktop/Local Repo/C Test Project/Memory_Pool/Memory_Pool/CMakeLists.txt;34;add_test;/home/abduljf/Desktop/Local Repo/C Test Project/Memory_Pool/Memory_Pool/CMakeLists.txt;0;")
add_test([=[ipool]=] "/home/abduljf/Desktop/Local Repo/C Test Project/Memory_Pool/Memory_Pool/binary/tests-out/init_pool_test")
set_tests_properties([=[ipool]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/abduljf/Desktop/Local Repo/C Test Project/Memory_Pool/Memory_Pool/CMakeLists.txt;38;add_test;/home/abduljf/Desktop/Local Repo/C Test Project/Memory_Pool/Memory_Pool/CMakeLists.txt;0;")
add_test([=[rpool]=] "/home/abduljf/Desktop/Local Repo/C Test Project/Memory_Pool/Memory_Pool/binary/tests-out/release_pool_test")
set_tests_properties([=[rpool]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/abduljf/Desktop/Local Repo/C Test Project/Memory_Pool/Memory_Pool/CMakeLists.txt;42;add_test;/home/abduljf/Desktop/Local Repo/C Test Project/Memory_Pool/Memory_Pool/CMakeLists.txt;0;")
