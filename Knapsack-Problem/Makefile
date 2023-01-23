include ../make.def
SOURCES = knapsack_problem.c
TARGET = knapsack

acc:
	${CLINK} ${CLINKFLAGS} -o ${SOURCES} ${TARGET} ${C_LIB}
run:
    ./${TARGET}
clean:
	rm $(TARGET)