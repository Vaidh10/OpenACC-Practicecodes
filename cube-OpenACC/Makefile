SOURCES = cubes_openacc.c cubes_serial_eric.c
TARGET = cubes
CFLAGS = -std=c99 -lm -O2
CC = gcc

acc:
	$(CC) $(SOURCES) $(CFLAGS) -fopenacc -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm $(TARGET)