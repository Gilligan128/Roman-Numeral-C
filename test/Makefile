
CFLAGS =  `pkg-config --cflags check`
LIBS = `pkg-config --libs check`
VPATH=../src
        
TEST_OBJECTS = alltests.o addition_tests.o sort_tests.o \
		grouping_tests.o subtractive_tests.o \
		validation_tests.o

OBJECTS = addition.o sort.o grouping.o subtractives.o \
	  validate.o roman_string.o

.PHONY: clean test 

test:  memtest
	./run_all_tests

run_all_tests: $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

memtest: run_all_tests 
	CK_FORK=no valgrind --leak-check=full ./run_all_tests

clean:
	rm -f *.o
	rm -f run_all_tests
