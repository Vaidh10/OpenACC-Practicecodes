SOURCES = cubes_openacc.c
CFLAGS = -fopenacc -lm
NVCFLAGS = -acc
CC = gcc

gcc_gpu:
    gcc $(SOURCES) $(CFLAGS) -o gcc_gpu

gcc_serial:
    gcc $(SOURCES) $(CFLAGS) -foffload=disable -o gcc_host
	
nvc_gpu:
    nvc $(SOURCES) $(NVCFLAGS) -ta=tesla -o gcc_gpu

nvc_multicore:
    nvc $(SOURCES) $(NVCFLAGS) -ta=multicore -o gcc_gpu

nvc_serial:
    nvc $(SOURCES) $(NVCFLAGS) -ta=host -o gcc_gpu

clean:
        rm $(TARGET)