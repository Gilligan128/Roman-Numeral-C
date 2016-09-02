
CFLAGS =  `pkg-config --cflags check`
LIBS = `pkg-config --libs check`
VPATH=../src
        
TEST_OBJECTS = addition_tests.o

OBJECTS = addition.o sort.o grouping.o subtractives.o

.PHONY: clean test 

test: run_all_tests
	./run_all_tests

run_all_tests: $(OBJECTS) $(TEST_OBJECTS) alltests.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

alltests.o: $(TEST_OBJECTS)

clean:
	rm -f *.o
	rm -f run_all_tests
