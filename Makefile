# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = job_system

# Source files
SRCS = main.cpp user.cpp candidate.cpp employer.cpp admin.cpp job.cpp matching_engine.cpp
OBJS = $(SRCS:.cpp=.o)

# Header files (all .h files)
HEADERS = user.h candidate.h employer.h admin.h job.h matching_engine.h

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp into .o (implicit rule)
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (not actual files)
.PHONY: all clean