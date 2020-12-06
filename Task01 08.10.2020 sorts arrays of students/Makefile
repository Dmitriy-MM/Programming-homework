CFLAGS = -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors  -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wno-long-long -Wmissing-declarations

BKY_FLAGS = -fsanitize=address -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format -O3

CFLAGS = $(BKY_FLAGS)

MAX_PRINT = 10

#VALGRIND = valgrind

all: a01.out a02.out a03.out a04.out a05.out a06.out a07.out a08.out a09.out a10.out
other: a01.out a02.out a03.out a04.out a05.out a06.out a07.out a08.out a09.out a10.out

student.o: student.h student.cpp
	g++ -c $(CFLAGS) student.cpp
in_out_array.o: in_out_array.cpp in_out_array.h
	g++ -c $(CFLAGS) in_out_array.cpp

a01.out: main01.o student.o sort01.o in_out_array.o
	g++ $(CFLAGS) main01.o student.o sort01.o in_out_array.o -o a01.out
main01.o: main01.cpp
	g++ -c $(CFLAGS) main01.cpp
sort01.o: sort01.cpp sorts.h
	g++ -c $(CFLAGS) sort01.cpp
	
a02.out: main02.o student.o sort02.o in_out_array.o
	g++ $(CFLAGS) main02.o student.o sort02.o in_out_array.o -o a02.out
main02.o: main02.cpp
	g++ -c $(CFLAGS) main02.cpp
sort02.o: sort02.cpp sorts.h
	g++ -c $(CFLAGS) sort02.cpp
	
a03.out: main03.o student.o sort03.o in_out_array.o
	g++ $(CFLAGS) main03.o student.o sort03.o in_out_array.o -o a03.out
main03.o: main03.cpp
	g++ -c $(CFLAGS) main03.cpp
sort03.o: sort03.cpp sorts.h
	g++ -c $(CFLAGS) sort03.cpp
	
a04.out: main04.o student.o sort04.o in_out_array.o
	g++ $(CFLAGS) main04.o student.o in_out_array.o sort04.o -o a04.out
main04.o: main04.cpp
	g++ -c $(CFLAGS) main04.cpp
sort04.o: sort04.cpp sorts.h
	g++ -c $(CFLAGS) sort04.cpp
	
a05.out: main05.o student.o sort05.o in_out_array.o
	g++ $(CFLAGS) main05.o student.o in_out_array.o sort05.o -o a05.out
main05.o: main05.cpp
	g++ -c $(CFLAGS) main05.cpp
sort05.o: sort05.cpp sorts.h
	g++ -c $(CFLAGS) sort05.cpp
	
a06.out: main06.o student.o sort06.o in_out_array.o
	g++ $(CFLAGS) main06.o student.o sort06.o in_out_array.o -o a06.out
main06.o: main06.cpp
	g++ -c $(CFLAGS) main06.cpp
sort06.o: sort06.cpp sorts.h
	g++ -c $(CFLAGS) sort06.cpp
	
a07.out: main07.o student.o sort07.o in_out_array.o
	g++ $(CFLAGS) main07.o student.o sort07.o in_out_array.o -o a07.out
main07.o: main07.cpp
	g++ -c $(CFLAGS) main07.cpp
sort07.o: sort07.cpp sorts.h
	g++ -c $(CFLAGS) sort07.cpp
	
a08.out: main08.o student.o sort08.o in_out_array.o
	g++ $(CFLAGS) main08.o student.o sort08.o in_out_array.o -o a08.out
main08.o: main08.cpp
	g++ -c $(CFLAGS) main08.cpp
sort08.o: sort08.cpp sorts.h
	g++ -c $(CFLAGS) sort08.cpp
	
a09.out: main09.o student.o sort09.o in_out_array.o
	g++ $(CFLAGS) main09.o student.o sort09.o in_out_array.o -o a09.out
main09.o: main09.cpp
	g++ -c $(CFLAGS) main09.cpp
sort09.o: sort09.cpp sorts.h
	g++ -c $(CFLAGS) sort09.cpp
	
a10.out: main10.o student.o sort10.o in_out_array.o
	g++ $(CFLAGS) main10.o student.o sort10.o in_out_array.o -o a10.out
main10.o: main10.cpp
	g++ -c $(CFLAGS) main10.cpp
sort10.o: sort10.cpp sorts.h
	g++ -c $(CFLAGS) sort10.cpp

test_1e2:
	echo "-------------------TEST4-------------------"
	$(VALGRIND) ./a04.out 100 $(MAX_PRINT) 0 test_1e2.txt
	echo "-------------------TEST5-------------------"
	$(VALGRIND) ./a05.out 100 $(MAX_PRINT) 0 test_1e2.txt
	echo "-------------------TEST6-------------------"
	$(VALGRIND) ./a06.out 100 $(MAX_PRINT) 0 test_1e2.txt
	echo "-------------------TEST7-------------------"
	$(VALGRIND) ./a07.out 100 $(MAX_PRINT) 0 test_1e2.txt
	echo "-------------------TEST8-------------------"
	$(VALGRIND) ./a08.out 100 $(MAX_PRINT) 0 test_1e2.txt
	echo "-------------------TEST9-------------------"
	$(VALGRIND) ./a09.out 100 $(MAX_PRINT) 0 test_1e2.txt
	echo "-------------------TEST10-------------------"
	$(VALGRIND) ./a10.out 100 $(MAX_PRINT) 0 test_1e2.txt

test_1e4:
	echo "-------------------TEST4-------------------"
	$(VALGRIND) ./a04.out 10000 $(MAX_PRINT) 0 test_1e4.txt
	echo "-------------------TEST5-------------------"
	$(VALGRIND) ./a05.out 10000 $(MAX_PRINT) 0 test_1e4.txt
	echo "-------------------TEST6-------------------"
	$(VALGRIND) ./a06.out 10000 $(MAX_PRINT) 0 test_1e4.txt
	echo "-------------------TEST7-------------------"
	$(VALGRIND) ./a07.out 10000 $(MAX_PRINT) 0 test_1e4.txt
	echo "-------------------TEST8-------------------"
	$(VALGRIND) ./a08.out 10000 $(MAX_PRINT) 0 test_1e4.txt
	echo "-------------------TEST9-------------------"
	$(VALGRIND) ./a09.out 10000 $(MAX_PRINT) 0 test_1e4.txt
	echo "-------------------TEST10-------------------"
	$(VALGRIND) ./a10.out 10000 $(MAX_PRINT) 0 test_1e4.txt
	
test_1e6:
	echo "-------------------TEST8-------------------"
	$(VALGRIND) ./a08.out 1000000 $(MAX_PRINT) 0 test_1e6.txt
	echo "-------------------TEST9-------------------"
	$(VALGRIND) ./a09.out 1000000 $(MAX_PRINT) 0 test_1e6.txt
	echo "-------------------TEST10-------------------"
	$(VALGRIND) ./a10.out 1000000 $(MAX_PRINT) 0 test_1e6.txt

clean: 
	rm -f *.out
	rm -f *.o
	rm -f *.exe
	
