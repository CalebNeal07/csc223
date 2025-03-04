CC=g++
STD=c++11

build/%.o: src/%.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	$(CC) -c -o $@ $< -std=$(STD)

build/test_stack: build/test_stack.o
	$(CC) -o $@ $^ -std=$(STD)

-include build/*.d

.PHONY: test clean

test: build/test_stack
	./build/test_stack

build: build/main
	./build/main

clean:
	rm -rf build
