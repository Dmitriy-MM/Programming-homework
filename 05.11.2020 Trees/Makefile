WINDOWS_FLAGS = -O3 -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors  -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wno-long-long -Wmissing-declarations
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
done: a01.out a02.out a03.out a04.out a05.out

student.o: student.cpp student.h
tree_node.o: tree_node.cpp tree_node.h student.h
tree.o: tree.cpp tree.h tree_node.h
tree_tasks.o: tree_tasks.cpp tree.h tree_node.h

a.out: main.o tree_tasks.o tree.o tree_node.o student.o
	g++ $(CFLAGS) $^ -o $@
main.o: main.cpp tree.h

test: a.out
	echo "++++++++++++++++++++++EMPTY++++++++++++++++++++++++"
	$(VALGRIND) ./a.out $(MAX_DEEP) tests/empty.txt
	echo "++++++++++++++++++++++SINGLETON++++++++++++++++++++"
	$(VALGRIND) ./a.out $(MAX_DEEP) tests/singleton.txt
	echo "++++++++++++++++++++++TEST1++++++++++++++++++++++++"
	$(VALGRIND) ./a.out $(MAX_DEEP) tests/test1.txt
	echo "++++++++++++++++++++++TEST2++++++++++++++++++++++++"
	$(VALGRIND) ./a.out $(MAX_DEEP) tests/test2.txt
	echo "++++++++++++++++++++++TEST3++++++++++++++++++++++++"
	$(VALGRIND) ./a.out $(MAX_DEEP) tests/test3.txt
	echo "++++++++++++++++++++++TEST4++++++++++++++++++++++++"
	$(VALGRIND) ./a.out $(MAX_DEEP) tests/test4.txt

clean: 
	rm -f *.out
	rm -f *.o
	rm -f *.exe
