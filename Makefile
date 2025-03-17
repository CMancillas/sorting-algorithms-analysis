# Compile to to use
CC = gcc

# Compiler flags:
#-Wall		: Enable all warning to help detect potential issues
#Iinclude	: Tell the compiler to look for header files in the "include" directory
CFLAGS = -Wall -Iinclude

# List of source files (.c files)
SRC = src/main.c src/insertion_sort.c src/test_cases.c src/time_measurement.c src/gnuplot_script.c src/selection_sort.c

# List of object files (.o files) automatically generated from source files
# This replace each .c file extension with .o
OBJ = $(SRC:.c=.o)

# Name of the final executable
OUT = insertion_sort

# Default target: Build the final executable
all: $(OUT)

# Rule to create the executable from object files
$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ)

# Clean rule: remove compiled object files and the executable
clean:
	rm -f $(OBJ) $