# the compiler: gcc for C program
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# used libs
LIBS += -lm

program: src/main.c
	$(CC) $(CFLAGS) -o program src/main.c $(LIBS)

test:
	./program < tests/first/stdin > tests/first/test_stdout
	diff tests/first/expected_stdout tests/first/test_stdout

	./program < tests/second/stdin > tests/second/test_stdout
	diff tests/second/expected_stdout tests/second/test_stdout

clean: 
	$(RM) program tests/first/test_stdout tests/second/test_stdout