SOURCES = knapsack_problem.c
CFLAGS = -acc -ta=tesla -Minfo=accel
CC = nvc
TARGET = knapsack

acc:
	$(CC) $(SOURCES) $(CFLAGS) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm $(TARGET)