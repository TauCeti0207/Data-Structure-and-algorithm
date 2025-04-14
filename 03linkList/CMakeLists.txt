# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(MyProject)

# 设置 C 标准
set(CMAKE_C_STANDARD 11)

# 添加可执行文件
add_executable(03SinglyLinkedList SinglyLinkedList.c test_singly_linked_list.c)
add_executable(03OJ_test OJ_test.c)
add_executable(03OJ_test02 OJ_test2.cpp)
add_executable(03doubly_circular_list doubly_circular_list.c test_doubly_circular_list.c)

