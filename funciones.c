// Funciones y Procedimientos

/*Metodo que nos permite desplegar un menu por terminal.
*Nos permite 
*/

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
			menu2(s);
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

void menu2(EstrucSched* s){

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

void InsertarProceso(EstrucSched* s, Proceso* p, short prioridad){

	Proceso *aux = NULL;
	//printf("%d\n", prioridad);

	if(prioridad == 0){
		s-> q0-> numeroDeProcesos++;
		if(s-> q0 -> cabeza == NULL){
			s-> q0-> cabeza = p;
			s-> q0-> final = p;
			s-> q0-> cabeza-> siguiente = NULL;
			s-> q0-> cabeza-> anterior = NULL;
		}
		else{

			//printf("%d\n", p -> pid);
			//printf("%c\n", p -> estado);
			//printf("%f\n", p -> tiempo);
			//printf("%s\n", p -> comando);

			aux = s-> q0-> final;
			s-> q0-> final -> siguiente = p;
			s-> q0-> final -> anterior = aux;


			//ESTO DA ERROR
			//printf("%d\n", s-> q0-> final-> anterior -> pid);
			//printf("%c\n", s-> q0-> final-> anterior -> estado);
			//printf("%f\n", s-> q0-> final-> anterior -> tiempo);
			//printf("%s\n", s-> q0-> final-> anterior -> comando);
		}
		//printf("Se ha agregado el proceso con exito\n");
	}
}

/*

void ElimProceso(EstrucSched *s, long pid, short prio){

	long pidArgumento = pid;
	proceso * auxProceso;
	proceso * anteriorAux;
	proceso * siguienteAux;
	char *auxEstado;
	long *auxPid;

	if(prioridad == 0){

		int ayuda = 0;

		aux = s-> q0-> &cabeza
		if(aux == NULL){
			printf("No existe elementos en la cola\n");
		}
		if(aux != NULL){

			auxEstado = aux-> estado;
			auxPid = aux-> pid;

			while(ayuda == 0){

				if(auxPid == pidArgumento){

					if(auxEstado == 'L'){
						anteriorAux = aux -> anterior;
						siguienteAux = aux -> siguiente;

						aux -> anterior -> siguiente = siguienteAux;
						aux -> siguiente -> anterior = anteriorAux;
						printf("Se ha eliminado satifactoriamente el proceso de la cola\n");
						return;


					}
					else if(auxEstado == 'E'){
						ayuda = -1;
						printf("El proceso sigue en ejecucion. No puede ser eliminado\n");
					}

				}
				else{
					aux = aux-> siguiente;
					auxEstado = aux-> siguiente -> estado;
					auxPid = aux -> siguiente-> pid;
				}
			}
		}
	}
}

void ElimProcesoE(EstrucSched *s){

	Proces *p = NULL;
	long *pidTemp = NULL;
	short *prioTemp = NULL;

	*p = ProxProceso(&s);

	*pidTemp = p-> &pid;
	*prioTemp = p-> &prioridad;

	ElimProceso(&s, &pidTemp, &prioTemp);
}

Proceso *ProxProceso(EstrucSched *s){

	Proceso *p == NULL;
	char estadoTemp;

	int valor = s-> q0-> &numeroDeProcesos;
	if(valor == 0){
		valor = s-> q1-> &numeroDeProcesos;
	}
	else{
		*p = s-> q0 -> &cabeza
		estadoTemp = p-> &estado;
		if(estado != 'L)'){
			return *p
		}
		else{
			while(p != NULL){
				*p = s-> q0 -> cabeza -> &siguiente;
				estadoTemp = p->& estado;
				if(estado != 'L)'){
					return *p
				}

			}
		}
	}

}


void CambiarEstado(EstrucSched *s, Proceso* p, Estado newestado){

}

*/

EstrucSched *Construye(char *filename){

	//Estructuras y apuntadores

	EstrucSched *s;
	EstrucSched planificador;

	cola cola0;
	cola cola1;
	cola cola2;
	cola cola3;
	cola cola4;
	cola cola5;

	cola *c0;
	cola *c1;
	cola *c2;
	cola *c3;
	cola *c4;
	cola *c5;

	FILE* archivo;
	int pidAux;
	char estadoAux;
	int prioridadAux;
	float tiempoAux;
	char comandoAux[20];

	//Inicializaciones

	s = &planificador;
	c0 = &cola0;
	c1 = &cola1;
	c2 = &cola2;
	c3 = &cola3;
	c4 = &cola4;
	c5 = &cola5;

	s-> q0 = c0;
	s-> q1 = c1;
	s-> q2 = c2;
	s-> q3 = c3;
	s-> q4 = c4;
	s-> q5 = c5;

	s-> q0-> numeroDeProcesos = 0;
	s-> q1-> numeroDeProcesos = 0;
	s-> q2-> numeroDeProcesos = 0;
	s-> q3-> numeroDeProcesos = 0;
	s-> q4-> numeroDeProcesos = 0;
	s-> q5-> numeroDeProcesos = 0;

	s-> q0-> cabeza = NULL;
	s-> q0-> final = NULL;
	s-> q1-> cabeza = NULL;
	s-> q1-> final = NULL;
	s-> q2-> cabeza = NULL;
	s-> q2-> final = NULL;
	s-> q3-> cabeza = NULL;
	s-> q3-> final = NULL;
	s-> q4-> cabeza = NULL;
	s-> q4-> final = NULL;
	s-> q5-> cabeza = NULL;
	s-> q5-> final = NULL;


	archivo = fopen(filename, "r");

	while(fscanf(archivo, "%d %c %d %f %s", &pidAux, &estadoAux, &prioridadAux, &tiempoAux, comandoAux) != EOF){

		Proceso proc;
		Proceso *p;
		p = &proc; 

		p->pid = pidAux;
		p-> estado = estadoAux;
		p-> tiempo = tiempoAux;
		p-> comando = comandoAux;

		InsertarProceso(s, p, prioridadAux);
	}

	fclose(archivo);

	return s;

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
		printf("PID: %d   Estado: %c  Tiempo: %f   Comando: %s\n", p->pid, p->estado, p->tiempo, p->comando);
	}

	printf("Cola de prioridad 1:\n");
	printf("Cola de prioridad 2:\n");
	printf("Cola de prioridad 3:\n");
	printf("Cola de prioridad 4:\n");
	printf("Cola de prioridad 5:\n");
	printf("\n#####################################################################\n\n");

}
