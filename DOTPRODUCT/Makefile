SOURCES = src/dotproduct.c src/dotproduct_main.c src/Vector.c
TARGET = dotproduct
CFLAGS = -std=c99 -O2
CC = /opt/local/bin/gcc-mp-7

omp:
	$(CC) $(SOURCES) $(CFLAGS) -fopenmp -o $(TARGET)

acc:
	$(CC) $(SOURCES) $(CFLAGS) -fopenacc -o $(TARGET)

run:
	./$(TARGET) 100000000

clean:
	rm $(TARGET)
