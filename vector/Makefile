compiler_flags = -Wall -Werror -Wextra -Iinclude/

all: main.o
	g++ main.o -o main

clear:
ifeq ($(OS), Windows_NT)
	del *.o
else
	rm *.o
endif

main.o:
	g++ main.cpp -c $(compiler_flags)
