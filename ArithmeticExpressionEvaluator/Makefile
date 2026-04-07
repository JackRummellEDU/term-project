CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g -Iinclude

TARGET = build/evaluator
TEST_TARGET = build/tests

SRC_DIR = src
BUILD_DIR = build
TEST_DIR = test

SRCS = 	$(wildcard $(SRC_DIR)/*.cpp) 

MAIN_SRC = $(SRC_DIR)/main.cpp
CORE_SRCS = $(filter-out $(MAIN_SRC), $(SRCS))

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
CORE_OBJS = $(CORE_SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)

all: $(TARGET)

test: $(TEST_TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(TEST_TARGET): $(CORE_OBJS) $(TEST_SRCS)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SRCS) $(CORE_OBJS) -lgtest -lgtest_main
	
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)