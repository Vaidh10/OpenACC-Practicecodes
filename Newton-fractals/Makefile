SOURCES = newton_fractals_openacc.c
CFLAGS = -fopenacc -lm
NVCFLAGS = -acc

gcc_gpu:
    gcc $(SOURCES) $(CFLAGS) -o gcc_gpu

gcc_serial:
    gcc $(SOURCES) $(CFLAGS) -foffload=disable -o gcc_host
	
nvc_gpu:
    nvc $(SOURCES) $(NVCFLAGS) -ta=tesla -o nvc_gpu

nvc_multicore:
    nvc $(SOURCES) $(NVCFLAGS) -ta=multicore -o nvc_gpu

nvc_serial:
    nvc $(SOURCES) $(NVCFLAGS) -ta=host -o nvc_gpu

clean:
        rm -f gcc*
		rm -f nvc*