CC = gcc
CFLAGS = -Wall -Wextra

# Source file
SOURCE = DoublyCircularLinkedList.c

# Extract the target name from the source file name
TARGET = $(SOURCE:.c=)

# Default target
all: $(TARGET)

# Generate executable file
$(TARGET):
	$(CC) $(CFLAGS) -o main $(SOURCE)

# Clean generated files
clean:
	del /Q main.exe
