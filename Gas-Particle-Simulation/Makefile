#CC=gcc
CC=nvc
#CFLAGS=-O3 -fopenacc
CFLAGS=-acc -ta=multicore -Minfo=accel
#CFLAGS=-acc -ta=tesla -Minfo=accel
DEPS = partticle.h BoundBox.h physics.h draw2D.h bitmap.h
OBJ = main.o particle.o BoundBox.o physics.o draw2D.o bitmap.o
LIBS = -lm 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

compute: main
	ncu --set full -o main -f ./main

systems: main
	nsys profile -o main.qdrep --trace openacc ./main

.PHONY: clean

clean:
	rm -f *.o main *.qdrep *.ncu-rep *.out