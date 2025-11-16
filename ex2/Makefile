# Compiler options
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS = main.cpp ../ex1/Lexer.cpp ../ex1/Token.cpp Rec.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = parser

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
