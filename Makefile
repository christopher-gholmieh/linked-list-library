# Written by: Christopher Gholmieh
# Source:
COMPILER_SOURCE=./linked-list-test.c

# Flags:
COMPILER_FLAGS=-Wextra -Wpedantic -Wall -Werror


# Build:
all:
	gcc $(COMPILER_FLAGS) $(COMPILER_SOURCE) -o ./linked-list-test
