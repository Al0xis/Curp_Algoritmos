#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Estructura que tiene los datos para generar el curp, y guardarlo
typedef struct Curp
{
	char* primer_nombre;
	char* segundo_nombre;
	char* primer_apellido;
	char* segundo_apellido;
	char* estado_nacimiento;
	char* fecha_nacimiento;
	char* sexo;
	char* curp_generado;
} Curp;

//Estructura de los nodos
typedef struct Nodo
{
	char primer_nombre[11];
	char segundo_nombre[11];
	char primer_apellido[16];
	char segundo_apellido[11];
	char fecha_nacimiento[11];
	char curp_generado[19];
	struct Nodo* siguiente;	
} Nodo;

//Estructura de la lista
typedef struct Lista
{
	struct Nodo* cabeza;
	size_t n;
} Lista;

//Funciones que ayudan con la gestion de la lista
Nodo* crear_nodo(Curp* datos);
Lista* crear_lista(void);
Nodo* agregar_nodo(Lista** lista, Curp* datos);
void imprimir_lista(Lista* lista);
void liberar_lista(Lista* lista);

//Funcion que gestiona la creacion del curp
void curp(unsigned opc_cri, unsigned opc_alg);

//Funciones para crear la memoria donde se guardaran las cadenas de caracteres
void crear(Curp* estructura_datos);
char* crear_memoria(unsigned tam);

//Funcion para buscar las vocales o consonantes internas de las cadenas o convertir cadenas a enteros
char vocal(char* cadena, int tam);
char consonante(char* cadena, int tam);
int convertir(char* cadena);

//Funcion para generar la curp
void generar_curp(Curp* estructura_datos);

//Funciones para obtener los datos
void obtener_datos(Curp* estructura_datos);

//Funcion para borrar la memoria
void borrar_memoria(Curp* estructura_datos);

//Funciones para ordenar
void burbuja(Lista* lista, unsigned opc);
void insercion(Lista* lista, unsigned opc);
void seleccion(Lista* lista, unsigned opc);

//Funciones de busqueda
size_t secuencial(Lista* lista, char* encontrar)

//Funciones para los menus
void opc_ordenar(void);
void opc_algoritmos(unsigned opc_cri);