# Parameters to control Makefile operation
PROJECT=inheritance
CC=g++
CFLAGS=-c -Wall -std=c++14
LDFLAGS=
SRC_DIR=.
BUILD_DIR=build
SOURCES=$(wildcard $(SRC_DIR)/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

# Default
all: main

# Make (link) an executable
main: $(SOURCES) $(PROJECT)

# Make (link) an executable
# Must have objects
$(PROJECT): $(OBJECTS)
	mkdir -p $(BUILD_DIR)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(BUILD_DIR)/$@.out

# Make (compile) an object
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

# Remove object files and the executable
clean:
	rm -f $(SRC_DIR)/*.o $(BUILD_DIR)/$(PROJECT).out

# Run the executable
run:
	./$(BUILD_DIR)/$(PROJECT).out

# Don't display instructions while running
.SILENT: run
