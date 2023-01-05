include ../make.def
SOURCES = matrix-multiplication_openacc.c
TARGET = matrix-multiplication_openacc

acc:
	${CLINK} ${CLINKFLAGS} -o ${SOURCES} ${TARGET} ${C_LIB}
run:
    ./${TARGET}
clean:
	rm $(TARGET)