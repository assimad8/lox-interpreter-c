# Compiler
CC = gcc

# Directories
SRC_DIR   = src
INC_DIR   = include
BUILD_DIR = build
BIN_DIR   = bin

# Target name
TARGET = clox

# Source files
SRC = main.c $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))

# Flags
CFLAGS_COMMON = -Wall -Wextra -std=c99 -I$(INC_DIR)

CFLAGS_DEBUG   = $(CFLAGS_COMMON) -g -O0
CFLAGS_RELEASE = $(CFLAGS_COMMON) -O2

# Default = debug
all: debug

# ------------------------
# Debug build
# ------------------------
debug: CFLAGS = $(CFLAGS_DEBUG)
debug: dirs $(BIN_DIR)/$(TARGET)

# ------------------------
# Release build
# ------------------------
release: CFLAGS = $(CFLAGS_RELEASE)
release: dirs $(BIN_DIR)/$(TARGET)

# ------------------------
# Link
# ------------------------
$(BIN_DIR)/$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# ------------------------
# Compile each .c -> .o
# ------------------------
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ------------------------
# Create folders
# ------------------------
dirs:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)

# ------------------------
# Run (debug build)
# ------------------------
run: debug
	./$(BIN_DIR)/$(TARGET)

# ------------------------
# Clean
# ------------------------
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# ------------------------
# Full rebuild
# ------------------------
rebuild: clean all
