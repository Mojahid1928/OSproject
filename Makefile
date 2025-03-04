# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Source files
SRC = main.cpp cli.cpp core.cpp utils.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = emulator

# Build rules
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: all
	./$(TARGET)
