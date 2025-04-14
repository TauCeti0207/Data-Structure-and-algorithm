# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(MyProject)

# 设置 C 标准
set(CMAKE_C_STANDARD 11)

# 添加可执行文件
add_executable(04stack stack.c test_stack.c)
add_executable(04queue queue.c test_queue.c)
add_executable(04circular_queue circular_queue.c test_circular_queue.c)

