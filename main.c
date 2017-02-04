//#include <stdio.h>
#include "colasPrioridades.h"
#include "interfaz.h"

int main (int argc, char** argv) 
{
    EstrucSched* s = NULL;
    s = Construye(argv[1]);
    menu (s, argv[2]);
    
	return 0;
}