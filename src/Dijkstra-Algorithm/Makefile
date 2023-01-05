include ../make.def
SOURCES = Dijkstra_openacc.c
TARGET = dijkstra

acc:
	${CLINK} ${CLINKFLAGS} -o ${SOURCES} ${TARGET} ${C_LIB}
run:
    ./${TARGET}
clean:
	rm $(TARGET)