# planificador-de-procesos

Desarrollo en C de la estructura de datos y funciones asociadas para la implementación de un planificador de procesos.

El archivo main.c es donde el programa inicia. En él se crea la estructura de colas de prioridades y posteriormente se inicia la ejecucion del menu.

La estructura de colas de prioridades se puede ver en el archivo colasPrioridades.h, en el se utilizan 6 colas dentro de un struct para manejar el planificador de procesos.

Para el desarrollo de las colas de prioridades se implemento una estructura de colas, donde un nodo tiene un apuntador hacia el nodo anterior, a un proceso, y al nodo siguiente.

Cada cola guarda informacion de un proceso y para implementar la informacion de cada proceso, en el archivo proceso.h, se denieron sus atributos dentro de un struct.

El metodo menu llamado al inicio del programa se ejecuta desde el archivo interfaz.c. En él mismo se encuentrar todas las instrucciones para desplegar informacion por la terminal.

Por ultimo, la mayor parte de las opciones desplegadas por la terminal están definidas en el archivo rutinas.h
