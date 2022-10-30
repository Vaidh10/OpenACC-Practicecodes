SOURCES = pi.c
TARGET = pi
CFLAGS = -ta=tesla -Minfo=accel
CC = nvc

acc:
	$(CC) $(SOURCES) $(CFLAGS) -o $(TARGET)

run:
	./$(TARGET) 100000000

clean:
	rm $(TARGET)
