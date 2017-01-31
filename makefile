all: pscheduler

# Esta regla compila el programa principal
pscheduler: main.o cola.o colasPrioridades.o interfaz.o proceso.o rutinas.o
	gcc -o pscheduler main.o cola.o colasPrioridades.o interfaz.o proceso.o rutinas.o


main.o: main.c colasPrioridades.h interfaz.h
	gcc -c main.c

cola.o: cola.h interfaz.h
	gcc -c cola.c

colaPrioridades.o: colasPrioridades.h rutinas.h
	gcc -c colasPrioridades.c

interfaz.o: interfaz.h colasPrioridades.h
	gcc -c interfaz.c

proceso.o: proceso.h
	gcc -c proceso.c

rutinas.o: rutinas.h
	gcc -c rutinas.c

clean:
	rm -f pscheduler *.o
