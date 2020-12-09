WINDOWS_FLAGS = -g -O3 -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors  -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wno-long-long -Wmissing-declarations
LINUX_FLAGS = -O3 -fsanitize=address -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format
CFLAGS = $(LINUX_FLAGS)

MAX_DEEP = 5
#VALGRIND = valgrind
#CFLAGS = -O3 -W -Wall -Wcast-align -pedantic -pedantic-errors  -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wno-long-long -Wmissing-declarations

%.o: %.cpp
	 g++ -c $(CFLAGS) $< -o $@

current: a.out
other: 
done: 

student.o: student.cpp student.h
main.o: main.cpp rb_tree.h student.h

a.out: main.o student.o 
	g++ $(CFLAGS) $^ -o $@


clean: 
	rm -f *.out
	rm -f *.o
	rm -f *.exe
