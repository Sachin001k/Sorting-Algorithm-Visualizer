CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

TARGET = ride_sharing

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJ)
