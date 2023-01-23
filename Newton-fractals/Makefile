include ../make.def
SOURCES = newton_fractals_openacc.c
TARGET = newton_fractals_openacc

acc:
	${CLINK} ${CLINKFLAGS} -o ${SOURCES} ${TARGET} ${C_LIB}
run:
    ./${TARGET}
clean:
	rm $(TARGET)