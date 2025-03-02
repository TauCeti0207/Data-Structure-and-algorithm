# @Descripttion: 
# @Author: tauceti0207
# @version: 
# @Date: 2025-02-28 13:50:44
# @LastEditors: tauceti0207
# @LastEditTime: 2025-03-01 22:57:44
# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(MyProject)

# 设置 C 标准
set(CMAKE_C_STANDARD 11)

# 添加可执行文件
add_executable(01test_algorithm 01.c)
add_executable(01test_algorithm_2 02.c)