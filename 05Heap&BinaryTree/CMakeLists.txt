
# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(MyProject)

# 设置 C 标准
set(CMAKE_C_STANDARD 11)

# 添加可执行文件
add_executable(05heap heap.c test_heap.c)
add_executable(05BTree BTree.c queue.c)

