TARGET = jacobi
CFLAGS = -ta=tesla -Minfo=accel
CC = nvc

parallel_bad:
	$(CC) Parallel_Bad/jacobi.c Parallel_Bad/laplace2d.c $(CFLAGS) -o $(TARGET)

parallel_good:
	$(CC) Parallel_Good/jacobi.c Parallel_Good/laplace2d.c $(CFLAGS) -o $(TARGET)

parallel_with_updates:
	$(CC) Parallel_With_Updates/jacobi.c Parallel_With_Updates/laplace2d.c $(CFLAGS) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm $(TARGET)