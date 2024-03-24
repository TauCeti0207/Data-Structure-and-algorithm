CC = gcc
CFLAGS = -Wall -Wextra

# 定义目标文件
OBJECTS = linkList.o

# 默认的目标
all: linkList

# 生成可执行文件
linkList: $(OBJECTS)
	$(CC) $(CFLAGS) -o linkList $(OBJECTS)

# 生成目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f linkList $(OBJECTS)