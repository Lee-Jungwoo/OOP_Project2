
CXX = g++
CXXFLAGS = -Wall -g -std=c++11
LDFLAGS =

EXEC = Calculator_1
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = $(wildcard *.h)


all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC) $(LDFLAGS)


%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(EXEC) $(OBJECTS)


$(OBJECTS): $(HEADERS)

-include $(OBJECTS:.o=.d)


%.d: %.cpp
	@$(CXX) $(CXXFLAGS) -MM -MT $(@:.d=.o) $< > $@

.PHONY: all clean