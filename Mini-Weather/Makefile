include ../make.def
SOURCES = mini_weather_openacc.cpp
TARGET = miniWeather

acc:
	${CLINK} ${CLINKFLAGS} -o ${SOURCES} ${TARGET} ${C_LIB}
run:
    ./${TARGET}
clean:
	rm $(TARGET)