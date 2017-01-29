/*Tarea 1 de Sistema de Operacion
*Integrantes: 
*	Andres Buelvas 13-10184
*	Juan Ortiz 13-
*
*/

#include "funciones.h"
#include "funciones.c"

int main(int argc, char* argv[]){

	nombreArchivoEntrada = argv[1];
	nombreArchivoSalida = argv[2];

	menu(Construye(nombreArchivoEntrada));

	return 0;

}


