#include "interfaz.h"
#include "colasPrioridades.h"

// Metodo que imprime opciones en la terminal
void menu(EstrucSched* s){

	printf("\nBienvenido al Planificador de Procesos A&J\n");
	int opcion;

	do{
		printf("\n1- Insertar proceso\n");
		printf("2- Eliminar proceso\n");
		printf("3- Cambiar estado del proceso\n");
		printf("4- Imprimir el contenido del planificador de Procesos\n");
		printf("0- Salir del programa\n\n");
		printf(">>>>>> ");
		scanf("%d", &opcion);

		if(opcion == 0){
			printf("Gracias por usar el planificador de Procesos A&J\n\n");
			break;
		}
		else if(opcion == 1){
			printf("Opcion ingresar\n");
			//InsertarProceso(&s, &p, prioridad);
			menu(s);
		}
		else if(opcion == 2){
			printf("0pcion eliminar\n");
			menuInterno(s);
			menu(s);
			//ElimProceso(&s, pid, prio);
		}
		else if(opcion == 3){
			printf("0opcion cambiar estado\n");
			//CambiarEstado(&p);
			menu(s);
		}
		else if(opcion == 4){
			Imprime(s);
			//menu(s);
		}
		else{
			printf("Opcion Invalida. Intente nuevamente\n");
			//menu(s);
		}

	}while( 0 > opcion && opcion > 4);
}

void menuInterno(EstrucSched* s){

	int opcion2;

	do{
		printf("\n1- Eliminar proceso\n");
		printf("2- Eliminar proceso en Ejecucion\n");
		printf("0- Regresar al menu principal\n\n");
		printf(">>>>>> ");
		scanf("%d", &opcion2);

		if(opcion2 == 1){
			printf("Opcion elimar proceso\n");
			//ElimProceso(&s, pid, prioridad);
			menu(s);
		}
		else if(opcion2 == 2){
			printf("Opcion eliminar proceso de ejecucion\n");
			//ElimProcesoE(&s);
			menu(s);
		}
		else if(opcion2 == 0){
			menu(s);
		}
	}while( 0 > opcion2 && opcion2 > 2);

}

void Imprime(EstrucSched *s){
    
    Proceso *p = NULL;
    
    printf("\n#####################################################################\n");
    printf("Informacion del planificador de procesos: \n\n");
    
    printf("Cola de prioridad 0:\n");
    
    //p = s-> q0-> cabeza;
    //printf("holiwis\n");
    //printf("%d\n", d);
    
    while(p != NULL){
        printf("PID: %d   Estado: %c  Tiempo: %f   Comando: %s\n", p->pid, p->estado, p->time, p->comando);
    }
    
    printf("Cola de prioridad 1:\n");
    printf("Cola de prioridad 2:\n");
    printf("Cola de prioridad 3:\n");
    printf("Cola de prioridad 4:\n");
    printf("Cola de prioridad 5:\n");
    printf("\n#####################################################################\n\n");
    
}