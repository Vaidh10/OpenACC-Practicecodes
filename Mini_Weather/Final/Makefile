CC := pgc++
CFLAGS := -O3 -w
ACCFLAGS_1 := -fast -ta=tesla,managed -Minfo=accel
ACCFLAGS_2 := -fast -ta=tesla -Minfo=accel
LDFLAGS :=  -lnetcdf -ldl
NVTXLIB := -I/opt/pgi/linux86-64-llvm/2019/cuda/10.1/include/

miniWeather_inter: miniWeather_inter.cpp
	${CC} ${CFLAGS} ${ACCFLAGS_1} -o miniWeather miniWeather_inter.cpp ${NVTXLIB} ${LDFLAGS}

miniWeather_final: miniWeather_final.cpp
	${CC} ${CFLAGS} ${ACCFLAGS_2} -o miniWeather miniWeather_final.cpp ${NVTXLIB} ${LDFLAGS}

clean:
	rm -f *.o miniWeather
