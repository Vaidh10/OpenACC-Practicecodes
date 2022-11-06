SOURCES = matrix-multiplication_openacc.c
TARGET = matrix-multiplication_openacc
CFLAGS = -acc -ta=tesla -Minfo=accel
CC = nvc

acc:
	$(CC) $(SOURCES) $(CFLAGS) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm $(TARGET)