CC = gcc
CFLAGS = -Wall -Wextra

# Source file
SOURCE = sequenceList.c

# Extract the target name from the source file name
TARGET = $(SOURCE:.c=)

# Default target
all: $(TARGET)

# Generate executable file
$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Clean generated files
clean:
	del /Q $(TARGET).exe
