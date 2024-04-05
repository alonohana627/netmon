# Compiler
CC := gcc

# Directories
SRC_DIR := src
LIB_DIR := lib
INCLUDE_DIR := include
BUILD_DIR := build

# Flags
CFLAGS := -Wall -Wextra -O2 -Wpedantic -I$(INCLUDE_DIR)

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
LIB_FILES := $(wildcard $(LIB_DIR)/*.c)

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
OBJ_FILES += $(patsubst $(LIB_DIR)/%.c,$(BUILD_DIR)/%.o,$(LIB_FILES))

# Targets
all: $(BUILD_DIR)/main

$(BUILD_DIR)/main: $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/main