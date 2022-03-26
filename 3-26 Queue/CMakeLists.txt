project(QUEUE) # 项目名称
aux_source_directory(./src SRCS) #SRCS 是一个宏
add_executable(${PROJECT_NAME} ${SRCS}) # 可执行文件
