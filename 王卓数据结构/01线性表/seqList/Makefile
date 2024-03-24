CC = gcc
CFLAGS = -Wall -Wextra

# 定义目标文件
OBJECTS = sequenceList.o

# 默认的目标
all: sequenceList

# 生成可执行文件
sequenceList: $(OBJECTS)
	$(CC) $(CFLAGS) -o sequenceList $(OBJECTS)

# 生成目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f sequenceList $(OBJECTS)