SOURCES = cubes_openacc.c cubes_serial_eric.c
TARGET = cubes
CFLAGS = -ta=tesla -Minfo=accel -lm
CC = nvc

acc:
	$(CC) $(SOURCES) $(CFLAGS) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm $(TARGET)