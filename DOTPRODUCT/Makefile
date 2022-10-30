SOURCES = src/dotproduct.c src/dotproduct_main.c src/Vector.c
TARGET = dotproduct
CFLAGS = -ta=tesla -Minfo=accel
CC = nvc

acc:
	$(CC) $(SOURCES) $(CFLAGS) -o $(TARGET)

run:
	./$(TARGET) 100000000

clean:
	rm $(TARGET)
