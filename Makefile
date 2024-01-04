CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra

SRC_DIR := .
BUILD_DIR := build
TARGET := NeuralNetwork 

# Collect all source and header files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
HDRS := $(wildcard $(SRC_DIR)/*.hpp)

# Generate corresponding object file names
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Main target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile each source file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean rule
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Ensure build directory exists
$(shell mkdir -p $(BUILD_DIR))