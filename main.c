//#include <stdio.h>
#include "colasPrioridades.h"
#include "interfaz.h"

int main (int argc, char** argv) 
{
    EstrucSched* s = NULL; //(EstrucSched *) malloc (sizeof (EstrucSched));
    s = Construye(argv[1]);
    menu (s);
    
	return 0;
}