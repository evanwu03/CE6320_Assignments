# Compiler
CXX       = g++
CPPFLAGS  = -Iinclude          # preprocessor flags (search paths, macros)
CXXFLAGS  = -Wall -Wextra -g   # compile flags
LDFLAGS   =
LDLIBS    =

# Sources and objects
SRCS := $(wildcard src/*.cpp)
OBJS := $(patsubst src/%.cpp,build/%.o,$(SRCS))

# Target
TARGET_NAME = hw1
TARGET = build/$(TARGET_NAME)

.PHONY: all clean run

all: $(TARGET)

# Link final executable
$(TARGET): $(OBJS) | build
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# Compile .cpp into build/
build/%.o: src/%.cpp | build
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Ensure build dir exists
build:
	mkdir -p $@

# Clean
clean:
	rm -rf build

# Run
run: all
	./$(TARGET)
