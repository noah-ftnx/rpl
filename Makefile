CXX=clang++


SRCDIR=.
SRCS:= $(shell find $(SRCDIR) -name "*.cpp")
OBJ= $(SRCS:%.cpp=%)
SRCS_UNDERSCORE:= $(shell find $(SRCDIR) -name "*_.cpp")
OBJ_UNDERSCORE= $(SRCS_UNDERSCORE:%.cpp=%)

INC=-I.
CXXFLAGS=-std=c++2a -Werror=return-type $(INC)

all: $(OBJ)

underscore: $(OBJ_UNDERSCORE)

# INFO:
# mkdir trick: creates all the dirs, and the last one that must have been a file
# then it deletes the last dir.
$(OBJ): %: %.cpp
	mkdir -p .bin/$(@D)
	$(CXX) $(CXXFLAGS) -o .bin/$@ $<
	@if [ -t 1 ] && [ -n "$$TERM" ]; then clear; fi
	.bin/$@

clean:
	rm -rf .bin
