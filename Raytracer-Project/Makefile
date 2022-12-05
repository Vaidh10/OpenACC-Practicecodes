include ../make.def
SOURCES = main.c
TARGET = raytracer

acc:
	${CLINK} ${CLINKFLAGS} -o ${SOURCES} ${TARGET} ${C_LIB}
run:
    ./${TARGET}
clean:
	rm $(TARGET)