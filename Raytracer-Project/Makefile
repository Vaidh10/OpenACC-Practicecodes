SOURCES = main.c
TARGET = raytracer
CFLAGS = -fopenacc
CC = g++

acc:
	$(CC) $(SOURCES) $(CFLAGS) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm $(TARGET)