include ../make.def
SOURCES = cubes_openacc.c
TARGET = cubes

acc:
	${CLINK} ${CLINKFLAGS} -o ${SOURCES} ${TARGET} ${C_LIB}
run:
    ./${TARGET}
clean:
	rm $(TARGET)