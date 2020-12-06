CFLAGS = -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors  -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wno-long-long -Wmissing-declarations
BKY_FLAGS = -fsanitize=address -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format -O3
CFLAGS = $(BKY_FLAGS)
MAX_PRINT = 20
#VALGRIND = valgrind

a%.out: main%.o 
	g++ $(CFLAGS) $^ -o $@
%.o: %.cpp
	 g++ -c $(CFLAGS) $< -o $@

all: done
other: a01.out a02.out a03.out a04.out a05.out a06.out a07.out a08.out
done: a01.out a02.out a03.out a05.out

student.o: student.cpp student.h
list_node.o: list_node.cpp list_node.h student.h
list.o: list.cpp list.h list_node.h list.h

a01.out: main01.o list01.o student.o list_node.o list.o
main01.o: main01.cpp
list01.o: list01.cpp list.h

a02.out: main02.o list02.o student.o list_node.o list.o
main02.o: main02.cpp
list02.o: list02.cpp list.h

a03.out: main03.o list03.o student.o list_node.o list.o
main03.o: main03.cpp
list03.o: list03.cpp list.h

a04.out: main04.o list04.o student.o list_node.o list.o
main04.o: main04.cpp
list04.o: list04.cpp list.h

a05.out: main05.o list05.o student.o list_node.o list.o
main05.o: main05.cpp
list05.o: list05.cpp list.h

a06.out: main06.o list06.o student.o list_node.o list.o
main06.o: main06.cpp
list06.o: list06.cpp list.h

a07.out: main07.o list07.o student.o list_node.o list.o
main07.o: main07.cpp
list07.o: list07.cpp list.h

a08.out: main08.o list08.o student.o list_node.o list.o
main08.o: main08.cpp
list08.o: list08.cpp list.h


clean: 
	rm -f *.out
	rm -f *.o
	rm -f *.exe
