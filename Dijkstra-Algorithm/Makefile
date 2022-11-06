SOURCES = Dijkstra_openacc.c
CFLAGS = -acc -ta=tesla -Minfo=accel
CC = nvc
TARGET = dijkstra

acc:
	$(CC) $(SOURCES) $(CFLAGS) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm $(TARGET)