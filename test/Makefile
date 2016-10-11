
CFLAGS = -std=gnu99 -Wall
LIBS = `pkg-config --libs check`
VPATH=../src   
TEST_OBJECTS := $(patsubst %.c,%.o,$(wildcard *.c))
OBJECTS := $(patsubst %.c,%.o,$(wildcard ../src/*.c))

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
