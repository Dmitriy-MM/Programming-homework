CFLAGS = -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors  -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wno-long-long -Wmissing-declarations
BKY_FLAGS = -fsanitize=address -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format 
CFLAGS = $(BKY_FLAGS)

MAX_PRINT = 10
#VALGRIND = valgrind
CFLAGS = -O3 -W -Wall -Wcast-align -pedantic -pedantic-errors  -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wno-long-long -Wmissing-declarations

a%.out: main%.o 
	g++ $(CFLAGS) $^ -o $@
%.o: %.cpp
	 g++ -c $(CFLAGS) $< -o $@

current: done
other: 
done: a01.out a02.out a03.out a04.out a05.out

student.o: student.cpp student.h
list_node.o: list_node.cpp list_node.h student.h
list.o: list.cpp list.h list_node.h list.h

a01.out: main01.o sort01.o student.o list_node.o list.o
main01.o: main01.cpp
sort01.o: sort01.cpp list.h

a02.out: main02.o sort02.o student.o list_node.o list.o
main02.o: main02.cpp
sort02.o: sort02.cpp list.h

a03.out: main03.o sort03.o student.o list_node.o list.o
main03.o: main03.cpp
sort03.o: sort03.cpp list.h

a04.out: main04.o sort04.o student.o list_node.o list.o
main04.o: main04.cpp
sort04.o: sort04.cpp list.h

a05.out: main05.o sort05.o student.o list_node.o list.o
main05.o: main05.cpp
sort05.o: sort05.cpp list.h

simple_test%: a0%.out
	echo "------------------EMPTY FILE---------------------"
	$(VALGRIND) ./$< $(MAX_PRINT) tests/empty.txt
	echo "------------------SINGLETON----------------------"
	$(VALGRIND) ./$< $(MAX_PRINT) tests/singleton.txt
	echo "------------------TETRA--------------------------"
	$(VALGRIND) ./$< $(MAX_PRINT) tests/tetra.txt
	echo "------------------SORTED-------------------------"
	$(VALGRIND) ./$< $(MAX_PRINT) tests/sorted_10.txt
	echo "------------------REVERSE------------------------"
	$(VALGRIND) ./$< $(MAX_PRINT) tests/reverse_10.txt
	echo "------------------REVERSE_x10--------------------"
	$(VALGRIND) ./$< $(MAX_PRINT) tests/reverse_10x10.txt

rand_simple_test%: a0%.out
	echo "------------------RANDOM_1e2----------------------"
	$(VALGRIND) ./$< $(MAX_PRINT) random_tests/random_1e2.txt
	echo "------------------RANDOM_1e3---------------------"
	$(VALGRIND) ./$< $(MAX_PRINT) random_tests/random_1e3.txt
	echo "------------------RANDOM_1e4---------------------"
	$(VALGRIND) ./$< $(MAX_PRINT) random_tests/random_1e4.txt
	echo "------------------RANDOM_1e5---------------------"
	$(VALGRIND) ./$< $(MAX_PRINT) random_tests/random_1e5.txt

rand_hard_test%: a0%.out
	echo "------------------RANDOM_1e6----------------------"
	./$< $(MAX_PRINT) random_tests/random_1e6.txt
	echo "------------------RANDOM_1e7---------------------"
	./$< $(MAX_PRINT) random_tests/random_1e7.txt
	echo "------------------RANDOM_1e8---------------------"
	./$< $(MAX_PRINT) random_tests/random_1e8.txt

test_bubble: a01.out
	echo "------------------RANDOM_1e6----------------------"
	./$< $(MAX_PRINT) tests/bubble_1e6.txt

clean: 
	rm -f *.out
	rm -f *.o
	rm -f *.exe
