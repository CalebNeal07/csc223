CC=g++
STD=c++11

build/%.o: src/%.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	$(CC) -c -o $@ $< -std=$(STD)

build/test_queues: build/test_queues.o
	$(CC) -o $@ $^ -std=$(STD)

-include build/*.d

.PHONY: test clean

test: build/test_queues
	./build/test_queues

clean:
	rm -rf build
