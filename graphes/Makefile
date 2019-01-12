# Compilation des programmes d'approximation des solutions

all: xy xt yt

app.exe: src_solution/*.c src_solution/*.h
	gcc -Wall src_solution/*.c -c
	gcc -Wall *.o -lm -o app.exe

xy: ./data/resXY.dat ./src_solution/scriptXY.gnuplot clean
	gnuplot ./src_solution/scriptXY.gnuplot

xt: ./data/resXt.dat ./src_solution/scriptXt.gnuplot clean
	gnuplot ./src_solution/scriptXt.gnuplot

yt: ./data/resYt.dat ./src_solution/scriptYt.gnuplot clean
	gnuplot ./src_solution/scriptYt.gnuplot

./data/resXY.dat: app.exe
	./app.exe parameters.txt

./data/resXt.dat: app.exe
	./app.exe parameters.txt

./data/resYt.dat: app.exe
	./app.exe parameters.txt


# Commpilation du programme de traçage du portrait de phase

phase.exe: src_phase/*.c src_phase/*.h
	gcc -Wall src_phase/*.c -lm -o phase.exe


# Suppression des fichiers inutiles

clean:
	rm -rf *o *~ src_solution/*~

cleanall: clean
	rm -rf ./data/*dat *svg *exe
