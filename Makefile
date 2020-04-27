main: main.o imagehelpers.o
	g++ -o main main.o imagehelpers.o

main.o: main.cpp imagehelpers.h

imagehelpers.o: imagehelpers.cpp imagehelpers.h

clean:
	rm -f main.o imagehelpers.o main task_A.pgm task_B.pgm task_C.pgm task_D.pgm task_E.pgm task_F.pgm
