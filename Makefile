CXX=clang++
CXXFLAGS=-std=c++2a

SRCDIR=.
SRCS:= $(shell find $(SRCDIR) -name "*.cpp")
OBJ= $(SRCS:%.cpp=%)

all: $(OBJ)

# INFO:
# mkdir trick: creates all the dirs, and the last one that must have been a file
# then it deletes the last dir.
$(OBJ): %: %.cpp
	mkdir -p .bin/$(@D)
	$(CXX) $(CXXFLAGS) -o .bin/$@ $<
	clear
	.bin/$@

clean:
	rm -rf .bin
