setup: miniWeather-serial.cpp
	mpicxx -acc -ta=multicore -fast -Minfo=accel miniWeather-serial.cpp -lpnetcdf -o miniWeather
gpu: miniWeather-serial.cpp
	mpicxx -acc -ta=tesla -fast -Minfo=accel miniWeather-serial.cpp -lpnetcdf -o miniWeather
clean:
	rm miniWeather