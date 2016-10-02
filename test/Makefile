
CFLAGS =  `pkg-config --cflags check`
LIBS = `pkg-config --libs check`
VPATH=../src
        
TEST_OBJECTS = alltests.o addition_tests.o sort_tests.o

OBJECTS = addition.o sort.o grouping.o subtractives.o

.PHONY: clean test 

test: run_all_tests
	./run_all_tests

run_all_tests: $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f run_all_tests
