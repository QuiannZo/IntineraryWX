# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Compiler and flags
CXX := g++
CXXFLAGS := `wx-config --cxxflags`
LIBS := `wx-config --libs`

# Source files and output binary
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEP := $(OBJ:.o=.d)
OUTPUT := $(BIN_DIR)/widgetTest

# Create the "bin" and "build" directories if they don't exist
$(shell mkdir -p $(BIN_DIR) $(BUILD_DIR))

all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LIBS) -o $(OUTPUT)

-include $(DEP)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean
