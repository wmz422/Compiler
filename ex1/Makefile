CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

TARGET = lexer
SRCS = main.cpp Lexer.cpp Token.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean