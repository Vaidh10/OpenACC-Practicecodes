SOURCES = newton_fractals_openacc.c
CFLAGS = -acc -ta=tesla -Minfo=accel
CC = nvc
TARGET = newton_fractals_openacc

acc:
	$(CC) $(SOURCES) $(CFLAGS) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm $(TARGET)