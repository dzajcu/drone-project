CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -iquote inc
INC=./inc
OBJ=./obj
SRC=./src

__start__: main.out
	./main.out

main.out: ${OBJ} ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/main.o ${OBJ}/macierz3D.o ${OBJ}/Wektor3D.o ${OBJ}/Prostopadloscian.o ${OBJ}/Graniastoslup.o ${OBJ}/Dron.o ${OBJ}/Obiekty.o ${OBJ}/Scena.o ${OBJ}/Powierzchnia.o
	g++ -o main.out ${OBJ}/main.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/macierz3D.o ${OBJ}/Wektor3D.o ${OBJ}/Prostopadloscian.o ${OBJ}/Dron.o ${OBJ}/Powierzchnia.o ${OBJ}/Graniastoslup.o ${OBJ}/Obiekty.o ${OBJ}/Scena.o -lpthread

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: ${SRC}/main.cpp ${INC}/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o ${OBJ}/main.o ${SRC}/main.cpp

${OBJ}/macierz3D.o: ${SRC}/macierz3D.cpp ${INC}/macierz3D.hh
	g++ ${CPPFLAGS} -o ${OBJ}/macierz3D.o ${SRC}/macierz3D.cpp

${OBJ}/Wektor3D.o: ${SRC}/Wektor3D.cpp ${INC}/Wektor3D.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Wektor3D.o ${SRC}/Wektor3D.cpp

${OBJ}/Prostopadloscian.o: ${SRC}/Prostopadloscian.cpp ${INC}/Prostopadloscian.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Prostopadloscian.o ${SRC}/Prostopadloscian.cpp

${OBJ}/Graniastoslup.o: ${SRC}/Graniastoslup.cpp ${INC}/Graniastoslup.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Graniastoslup.o ${SRC}/Graniastoslup.cpp

${OBJ}/Dron.o: ${SRC}/Dron.cpp ${INC}/Dron.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Dron.o ${SRC}/Dron.cpp

${OBJ}/Obiekty.o: ${SRC}/Obiekty.cpp ${INC}/Obiekty.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Obiekty.o ${SRC}/Obiekty.cpp

${OBJ}/Powierzchnia.o: ${SRC}/Powierzchnia.cpp ${INC}/Powierzchnia.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Powierzchnia.o ${SRC}/Powierzchnia.cpp

${OBJ}/Scena.o: ${SRC}/Scena.cpp ${INC}/Scena.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Scena.o ${SRC}/Scena.cpp

${OBJ}/Dr3D_gnuplot_api.o: ${INC}/Dr3D_gnuplot_api.hh ${SRC}/Dr3D_gnuplot_api.cpp 
	g++ ${CPPFLAGS} -o ${OBJ}/Dr3D_gnuplot_api.o ${SRC}/Dr3D_gnuplot_api.cpp

${INC}/Dr3D_gnuplot_api.hh: ${INC}/Draw3D_api_interface.hh
	touch ${INC}/Dr3D_gnuplot_api.hh

clear:
	rm main.out ${OBJ}/main.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/Wektor3D.o ${OBJ}/macierz3D.o ${OBJ}/Prostopadloscian.o ${OBJ}/Graniastoslup.o ${OBJ}/Dron.o ${OBJ}/Scena.o ${OBJ}/Powierzchnia.o ${OBJ}/Obiekty.o