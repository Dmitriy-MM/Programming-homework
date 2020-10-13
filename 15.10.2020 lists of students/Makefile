CFLAGS = -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors  -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wno-long-long -Wmissing-declarations
#BKY_FLAGS = -fsanitize=address -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format -O3
CFLAGS = $(BKY_FLAGS)
MAX_PRINT = 20
#VALGRIND = valgrind

a%.out: main%.o 
	g++ $(CFLAGS) $^ -o $@
%.o: %.cpp
	 g++ -c $(CFLAGS) $< -o $@

all: a01.out a02.out a03.out a04.out a05.out a06.out a07.out a08.out
other: 

student.o: student.cpp student.h
list_node.o: list_node.cpp list_node.h student.h
list_service.o: list_service.cpp list_service.h list_node.h

a01.out: main01.o list01.o student.o list_node.o list_service.o
main01.o: main01.cpp
list01.o: list01.cpp list_tasks.h

a02.out: main02.o list02.o student.o list_node.o list_service.o
main02.o: main02.cpp
list02.o: list02.cpp list_tasks.h

a03.out: main03.o list03.o student.o list_node.o list_service.o
main03.o: main03.cpp
list03.o: list03.cpp list_tasks.h

a04.out: main04.o list04.o student.o list_node.o list_service.o
main04.o: main04.cpp
list04.o: list04.cpp list_tasks.h

a05.out: main05.o list05.o student.o list_node.o list_service.o
main05.o: main05.cpp
list05.o: list05.cpp list_tasks.h

a06.out: main06.o list06.o student.o list_node.o list_service.o
main06.o: main06.cpp
list06.o: list06.cpp list_tasks.h

a07.out: main07.o list07.o student.o list_node.o list_service.o
main07.o: main07.cpp
list07.o: list07.cpp list_tasks.h

a08.out: main08.o list08.o student.o list_node.o list_service.o
main08.o: main08.cpp
list08.o: list08.cpp list_tasks.h

test1: a01.out
	$(VALGRIND) ./a01.out $(MAX_PRINT) tests/test1_01.txt
	echo "Right answer is 5"
	$(VALGRIND) ./a01.out $(MAX_PRINT) tests/test1_02.txt
	echo "Right answer is 4"
	$(VALGRIND) ./a01.out $(MAX_PRINT) tests/test1_03.txt
	echo "Right answer is 4"

test2: a02.out
	$(VALGRIND) ./a02.out $(MAX_PRINT) tests/test2_01.txt
	echo "Right answer is 8"
	$(VALGRIND) ./a02.out $(MAX_PRINT) tests/test2_02.txt
	echo "Right answer is 0"
	$(VALGRIND) ./a02.out $(MAX_PRINT) tests/test2_03.txt
	echo "Right answer is 1"
	$(VALGRIND) ./a02.out $(MAX_PRINT) tests/test2_04.txt
	echo "Right answer is 1"

test3: a03.out
	$(VALGRIND) ./a03.out $(MAX_PRINT) tests/test3_01.txt
	echo "Right answer is 4"
	$(VALGRIND) ./a03.out $(MAX_PRINT) tests/test3_02.txt
	echo "Right answer is 1"
	$(VALGRIND) ./a03.out $(MAX_PRINT) tests/test3_03.txt
	echo "Right answer is 1"
	$(VALGRIND) ./a03.out $(MAX_PRINT) tests/test3_04.txt
	echo "Right answer is 1"
	$(VALGRIND) ./a03.out $(MAX_PRINT) tests/test3_05.txt
	echo "Right answer is 5"
	$(VALGRIND) ./a03.out $(MAX_PRINT) tests/test3_06.txt
	echo "Right answer is 5"
	$(VALGRIND) ./a03.out $(MAX_PRINT) tests/test3_07.txt
	echo "Right answer is 7"

test4: a04.out
	$(VALGRIND) ./a04.out $(MAX_PRINT) tests/test4_01.txt
	echo "Right answer is 4"
	$(VALGRIND) ./a04.out $(MAX_PRINT) tests/test4_02.txt
	echo "Right answer is 3"
	$(VALGRIND) ./a04.out $(MAX_PRINT) tests/test4_03.txt
	echo "Right answer is 1"
	$(VALGRIND) ./a04.out $(MAX_PRINT) tests/test4_04.txt
	echo "Right answer is 2"
	$(VALGRIND) ./a04.out $(MAX_PRINT) tests/test4_05.txt
	echo "Right answer is 3"
	$(VALGRIND) ./a04.out $(MAX_PRINT) tests/test4_06.txt
	echo "Right answer is 1"
	$(VALGRIND) ./a04.out $(MAX_PRINT) tests/test4_07.txt
	echo "Right answer is 0"
	$(VALGRIND) ./a04.out $(MAX_PRINT) tests/test4_08.txt
	echo "Right answer is 2"
	$(VALGRIND) ./a04.out $(MAX_PRINT) tests/test4_09.txt
	echo "Right answer is 0"

test5: a05.out
	$(VALGRIND) ./a05.out $(MAX_PRINT) tests/test5_01.txt
	echo "Right answer is 1"
	$(VALGRIND) ./a05.out $(MAX_PRINT) tests/test5_02.txt
	echo "Right answer is 2"
	$(VALGRIND) ./a05.out $(MAX_PRINT) tests/test5_03.txt
	echo "Right answer is 5"
	$(VALGRIND) ./a05.out $(MAX_PRINT) tests/test5_04.txt
	echo "Right answer is 5"
	$(VALGRIND) ./a05.out $(MAX_PRINT) tests/test5_05.txt
	echo "Right answer is 5"

test6: a06.out
	$(VALGRIND) ./a06.out $(MAX_PRINT) tests/test6_01.txt
	echo "Right answer is 0"
	$(VALGRIND) ./a06.out $(MAX_PRINT) tests/test6_02.txt
	echo "Right answer is 1"
	$(VALGRIND) ./a06.out $(MAX_PRINT) tests/test6_03.txt
	echo "Right answer is 2"
	$(VALGRIND) ./a06.out $(MAX_PRINT) tests/test6_04.txt
	echo "Right answer is 4"
	$(VALGRIND) ./a06.out $(MAX_PRINT) tests/test6_05.txt
	echo "Right answer is 2"

test7: a07.out
	$(VALGRIND) ./a07.out $(MAX_PRINT) tests/test7_01.txt
	echo "Right answer is 0"
	$(VALGRIND) ./a07.out $(MAX_PRINT) tests/test7_02.txt
	echo "Right answer is 0"
	$(VALGRIND) ./a07.out $(MAX_PRINT) tests/test7_03.txt
	echo "Right answer is 0"
	$(VALGRIND) ./a07.out $(MAX_PRINT) tests/test7_04.txt
	echo "Right answer is 0"
	$(VALGRIND) ./a07.out $(MAX_PRINT) tests/test7_05.txt
	echo "Right answer is 0"
	$(VALGRIND) ./a07.out $(MAX_PRINT) tests/test7_06.txt
	echo "Right answer is 0"
	$(VALGRIND) ./a07.out $(MAX_PRINT) tests/test7_07.txt
	echo "Right answer is 0"
	$(VALGRIND) ./a07.out $(MAX_PRINT) tests/test7_08.txt
	echo "Right answer is 2"
	$(VALGRIND) ./a07.out $(MAX_PRINT) tests/test7_09.txt
	echo "Right answer is 4"
	$(VALGRIND) ./a07.out $(MAX_PRINT) tests/test7_10.txt
	echo "Right answer is 1"
	$(VALGRIND) ./a07.out $(MAX_PRINT) tests/test7_11.txt
	echo "Right answer is 0"
	$(VALGRIND) ./a07.out $(MAX_PRINT) tests/test7_12.txt
	echo "Right answer is 1"

test8: a08.out
	$(VALGRIND) ./a08.out $(MAX_PRINT) tests/test8_01.txt
	echo "Right answer is 1"
	$(VALGRIND) ./a08.out $(MAX_PRINT) tests/test8_02.txt
	echo "Right answer is 2"
	$(VALGRIND) ./a08.out $(MAX_PRINT) tests/test8_03.txt
	echo "Right answer is 2"
	$(VALGRIND) ./a08.out $(MAX_PRINT) tests/test8_04.txt
	echo "Right answer is 2"
	$(VALGRIND) ./a08.out $(MAX_PRINT) tests/test8_05.txt
	echo "Right answer is 3"
	$(VALGRIND) ./a08.out $(MAX_PRINT) tests/test8_06.txt
	echo "Right answer is 2"
	$(VALGRIND) ./a08.out $(MAX_PRINT) tests/test8_07.txt
	echo "Right answer is 2"
	$(VALGRIND) ./a08.out $(MAX_PRINT) tests/test8_08.txt
	echo "Right answer is 8"
	$(VALGRIND) ./a08.out $(MAX_PRINT) tests/test8_09.txt
	echo "Right answer is 9"
	$(VALGRIND) ./a08.out $(MAX_PRINT) tests/test8_10.txt
	echo 'Right answer is 10';

clean: 
	rm -f *.out
	rm -f *.o
	rm -f *.exe
