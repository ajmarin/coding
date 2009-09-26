SRC = $(wildcard *.cpp)
TRG = $(patsubst %.cpp,%,$(SRC))

%: $<.cpp
		g++ -Wall -lm $< -o $@

all: $(TRG)

clean:
		rm $(TRG)
