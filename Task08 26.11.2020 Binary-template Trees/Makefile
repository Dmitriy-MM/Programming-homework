WINDOWS_FLAGS =  -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors  -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wno-long-long -Wmissing-declarations
LINUX_FLAGS = -O3 -fsanitize=address -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format
CFLAGS = $(WINDOWS_FLAGS)

MAX_DEEP = 5
#VALGRIND = valgrind
#CFLAGS = -O3 -W -Wall -Wcast-align -pedantic -pedantic-errors  -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wno-long-long -Wmissing-declarations

#a%.out: main%.o 
#	g++ $(CFLAGS) $^ -o $@
%.o: %.cpp
	 g++ -c $(CFLAGS) $< -o $@

current: a.out
other: 
done: 

student.o: student.cpp student.h
tree.o: tree.cpp tree.h 
#tree_tasks.o: tree_tasks.cpp tree.h tree_node.h
list_2.o: list_2.cpp list_2.h list_2_node.h
list_2_node.o: list_2_node.cpp list_2_node.h student.h

main.o: main.cpp tree.h list_2.h list_2_node.h student.h

a.out: main.o tree.o list_2_node.o list_2.o student.o 
	g++ $(CFLAGS) $^ -o $@


big_test_1e2: a.out
		echo "--------test_1e2.txt---------"
		$(VALGRIND) ./a.out 0 tests/test_1e2.txt 1
		$(VALGRIND) ./a.out 0 tests/test_1e2.txt 2
		$(VALGRIND) ./a.out 0 tests/test_1e2.txt 4
		$(VALGRIND) ./a.out 0 tests/test_1e2.txt 10
		$(VALGRIND) ./a.out 0 tests/test_1e2.txt 20
		$(VALGRIND) ./a.out 0 tests/test_1e2.txt 30
		$(VALGRIND) ./a.out 0 tests/test_1e2.txt 99
		$(VALGRIND) ./a.out 0 tests/test_1e2.txt 200

big_test_1e4: a.out
		echo "--------test_1e4.txt---------"
		$(VALGRIND) ./a.out 0 tests/test_1e4.txt 1
		$(VALGRIND) ./a.out 0 tests/test_1e4.txt 2
		$(VALGRIND) ./a.out 0 tests/test_1e4.txt 5
		$(VALGRIND) ./a.out 0 tests/test_1e4.txt 14
		$(VALGRIND) ./a.out 0 tests/test_1e4.txt 25
		$(VALGRIND) ./a.out 0 tests/test_1e4.txt 37
		$(VALGRIND) ./a.out 0 tests/test_1e4.txt 49
		$(VALGRIND) ./a.out 0 tests/test_1e4.txt 110
		$(VALGRIND) ./a.out 0 tests/test_1e4.txt 185
		$(VALGRIND) ./a.out 0 tests/test_1e4.txt 244
		$(VALGRIND) ./a.out 0 tests/test_1e4.txt 333
		$(VALGRIND) ./a.out 0 tests/test_1e4.txt 571
		$(VALGRIND) ./a.out 0 tests/test_1e4.txt 1024
		$(VALGRIND) ./a.out 0 tests/test_1e4.txt 4897

big_test_1e6: a.out
		echo "--------test_1e6.txt---------"
		./a.out 0 tests/test_1e6.txt 2
		./a.out 0 tests/test_1e6.txt 10
		./a.out 0 tests/test_1e6.txt 100
		./a.out 0 tests/test_1e6.txt 1000
		./a.out 0 tests/test_1e6.txt 10000
		./a.out 0 tests/test_1e6.txt 100000
		./a.out 0 tests/test_1e6.txt 50
		./a.out 0 tests/test_1e6.txt 7
		./a.out 0 tests/test_1e6.txt 123

clean: 
	rm -f *.out
	rm -f *.o
	rm -f *.exe
