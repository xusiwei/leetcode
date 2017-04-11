CXXFLAGS += -std=c++11

SRCS = $(wildcard *.cc)
EXES = $(SRCS:.cc=.out)

test: all
	./test.sh

all: $(EXES)

%.out: %.cc
	$(CXX) $(CXXFLAGS) $< -o $@

clean: $(EXES)
	$(RM) $(EXES)
	./test.sh clean
