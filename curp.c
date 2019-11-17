#include"curp.h"

void crear(Curp* estructura_datos)
{
	estructura_datos->primer_nombre = crear_memoria(11);
	estructura_datos->segundo_nombre = crear_memoria(11);
	estructura_datos->primer_apellido = crear_memoria(16);
	estructura_datos->segundo_apellido = crear_memoria(16);
	estructura_datos->estado_nacimiento = crear_memoria(3);
	estructura_datos->fecha_nacimiento = crear_memoria(11);
	estructura_datos->sexo = crear_memoria(2);
	estructura_datos->curp_generado = crear_memoria(19);
}

char* crear_memoria(unsigned tam)
{
	char* nueva_cadena;
	nueva_cadena = (char*)malloc(tam*sizeof(char));
	if(nueva_cadena == NULL) 
	{
		printf("\nERROR\n");
		return NULL;
	}
	for(int i=0; i<tam; i++) nueva_cadena[i] = (char)00;
	return nueva_cadena;
}

void obtener_datos(Curp* estructura_datos)
{
	printf("\nIntroduzca todos los datos en mayuscula y sin acento");
	printf("\nIntroduzca el primer nombre: ");
	scanf("%s",estructura_datos->primer_nombre);
	printf("\nIntroduzca el segundo nombre(En caso de no tener introduzca X): ");
	scanf("%s",estructura_datos->segundo_nombre);
	printf("\nIntroduzca el primer apellido: ");
	scanf("%s",estructura_datos->primer_apellido);
	printf("\nIntroduzca el segundo apellido: ");	
	scanf("%s",estructura_datos->segundo_apellido);
	printf("\nIntroduzca la fecha de nacimiento(AAAA/MM/DD): ");
	scanf("%s",estructura_datos->fecha_nacimiento);
	printf("\nIntroduzca el sexo(H o M): ");
	scanf("%s",estructura_datos->sexo);
	printf("\nIntroduzca la clave de la entidad federativa de nacimiento: ");	
	scanf("%s",estructura_datos->estado_nacimiento);	
	printf("\n");	
}

char vocal(char* cadena, int tam)
{
	char vocales[]={'A', 'E', 'I', 'O', 'U'};
 	char vo = 'P';
 	for(int i=0; i<tam; i++)
 	{
 		for (int j=0; j<5; j++)
 		{
 			if(cadena[i+1] == vocales[j]) vo = vocales[j];
 			if(vo != 'P') break;
 		}
 		if(vo != 'P') break;
 	}	
 	return vo;
}

char consonante(char* cadena, int tam)
{
 	char consonante[]={'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', (char)165, 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
 	char co = 'A';
 	for(int i=0; i<tam; i++)
 	{
 		for (int j=0; j<22; j++)
 		{
 			if(cadena[i+1] == consonante[j]) co = consonante[j];
 			if(co != 'A') break;
 		}
 		if(co != 'A') break;
 	}	
 	return co;
}

void generar_curp(Curp* estructura_datos)
{
	if(estructura_datos->primer_apellido[0] == 165)	estructura_datos->curp_generado[0] = 'X';
	else estructura_datos->curp_generado[0] = estructura_datos->primer_apellido[0];
	estructura_datos->curp_generado[1] = vocal(estructura_datos->primer_apellido, 16);
	if(estructura_datos->primer_apellido[0] == 165)	estructura_datos->curp_generado[2] = 'X';
	else estructura_datos->curp_generado[2] = estructura_datos->segundo_apellido[0];
	estructura_datos->curp_generado[3] = estructura_datos->primer_nombre[0];
	estructura_datos->curp_generado[4] = estructura_datos->fecha_nacimiento[2];
	estructura_datos->curp_generado[5] = estructura_datos->fecha_nacimiento[3];
	estructura_datos->curp_generado[6] = estructura_datos->fecha_nacimiento[5];
	estructura_datos->curp_generado[7] = estructura_datos->fecha_nacimiento[6];
	estructura_datos->curp_generado[8] = estructura_datos->fecha_nacimiento[8];
	estructura_datos->curp_generado[9] = estructura_datos->fecha_nacimiento[9];
	estructura_datos->curp_generado[10] = estructura_datos->sexo[0];
	estructura_datos->curp_generado[11] = estructura_datos->estado_nacimiento[0];
	estructura_datos->curp_generado[12] = estructura_datos->estado_nacimiento[1];
	estructura_datos->curp_generado[13] = consonante(estructura_datos->primer_apellido, 16);
	estructura_datos->curp_generado[14] = consonante(estructura_datos->segundo_apellido, 16);
	estructura_datos->curp_generado[15] = consonante(estructura_datos->primer_nombre, 11);
	estructura_datos->curp_generado[16] = '0';
	estructura_datos->curp_generado[17] = '0';
}

Nodo* crear_nodo(Curp* datos)
{
	Nodo* nuevo_nodo;
	nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
	if(nuevo_nodo == NULL)
	{
		printf("\nERROR\n");
		return NULL;
	}
	strcpy(nuevo_nodo->primer_nombre, datos->primer_nombre);
	strcpy(nuevo_nodo->segundo_nombre, datos->segundo_nombre);
	strcpy(nuevo_nodo->primer_apellido, datos->primer_apellido);
	strcpy(nuevo_nodo->segundo_apellido, datos->segundo_apellido);
	strcpy(nuevo_nodo->fecha_nacimiento, datos->fecha_nacimiento);
	strcpy(nuevo_nodo->curp_generado, datos->curp_generado);
	nuevo_nodo->siguiente = NULL;
	return nuevo_nodo;
}

Lista* crear_lista(void)
{
	Curp inicializar;
	crear(&inicializar);
	Nodo* cabeza=NULL;
	Lista* lista;
	lista = (Lista*)malloc(sizeof(Lista));
	if(!lista)
	{
		printf("\nERROR\n");
		return NULL;
	}
	cabeza = crear_nodo(&inicializar);
	if(!cabeza) return NULL;
	lista->cabeza = cabeza;
	lista->n = 0;
	borrar_memoria(&inicializar);
	return lista; 
}

Nodo* agregar_nodo(Lista** lista, Curp* datos)
{
	Nodo* nodo;
	if(! *lista)
	{
		*lista = crear_lista();
		if(! *lista) return NULL;
		nodo = (*lista)->cabeza;
		strcpy(nodo->primer_nombre, datos->primer_nombre);
		strcpy(nodo->segundo_nombre, datos->segundo_nombre);
		strcpy(nodo->primer_apellido, datos->primer_apellido);
		strcpy(nodo->segundo_apellido, datos->segundo_apellido);
		strcpy(nodo->fecha_nacimiento, datos->fecha_nacimiento);
		strcpy(nodo->curp_generado, datos->curp_generado);
	}
	else
	{
		nodo = (*lista)->cabeza;
		while(nodo->siguiente) nodo = nodo->siguiente;
		nodo->siguiente = crear_nodo(datos);
		nodo = nodo->siguiente;
	}
	(*lista)->n++;
	return nodo;
}

void liberar_lista(Lista* lista)
{
	Nodo* nodo=lista->cabeza;
	while(nodo)
	{
		Nodo *objetivo=nodo;
		nodo = nodo->siguiente;
		free(objetivo);
	}
	free(lista);
}

void imprimir_lista(Lista* lista)
{
	Nodo* nodo=lista->cabeza;
	printf("\nContenido de la lista: %lu curps\n\n", lista->n);
	do
	{
		printf("\n");
		printf("%s", nodo->primer_nombre);
		printf("\n");	
		printf("%s", nodo->segundo_nombre);
		printf("\n");
		printf("%s", nodo->primer_apellido);
		printf("\n");
		printf("%s", nodo->segundo_apellido);
		printf("\n");
		printf("%s", nodo->fecha_nacimiento);
		printf("\n");
		printf("%s", nodo->curp_generado);
		printf("\n");
		nodo = nodo->siguiente;
	} while(nodo!=NULL);
	printf("\n");
}

void borrar_memoria(Curp* estructura_datos)
{
	free(estructura_datos->primer_nombre);
	free(estructura_datos->segundo_nombre);
	free(estructura_datos->primer_apellido);
	free(estructura_datos->segundo_apellido);
	free(estructura_datos->estado_nacimiento);
	free(estructura_datos->fecha_nacimiento);
	free(estructura_datos->sexo);
	free(estructura_datos->curp_generado);
}

int convertir(char* cadena)
{
	int fecha=0;
	if (cadena[0] == '1') fecha += 1000;
	if (cadena[0] == '2') fecha += 2000;

	if (cadena[1] == '9') fecha += 900;
	if (cadena[1] == '0') fecha += 0;

	if (cadena[2] == '0') fecha += 0;
	if (cadena[2] == '1') fecha += 10;
	if (cadena[2] == '2') fecha += 20;
	if (cadena[2] == '3') fecha += 30;
	if (cadena[2] == '4') fecha += 40;
	if (cadena[2] == '5') fecha += 50;
	if (cadena[2] == '6') fecha += 60;
	if (cadena[2] == '7') fecha += 70;
	if (cadena[2] == '8') fecha += 80;
	if (cadena[2] == '9') fecha += 90;

	if (cadena[2] == '0') fecha += 0;
	if (cadena[2] == '1') fecha += 1;
	if (cadena[2] == '2') fecha += 2;
	if (cadena[2] == '3') fecha += 3;
	if (cadena[2] == '4') fecha += 4;
	if (cadena[2] == '5') fecha += 5;
	if (cadena[2] == '6') fecha += 6;
	if (cadena[2] == '7') fecha += 7;
	if (cadena[2] == '8') fecha += 8;
	if (cadena[2] == '9') fecha += 9;

	return fecha;
}

void burbuja(Lista* lista)
{
	if(lista->n==1 || lista->n==0) return;
	Nodo* A;
	Nodo* B;
	A = lista->cabeza;
	int i=1; 
	Curp auxiliar;
	crear(&auxiliar); 
	int opc;
	printf("\nSeleccione el criterio para ordenar las curps:\n1) Primer nombre\n2) Primer apellido\n3) Fecha de nacimiento\nOpcion deseada: ");
	scanf("%d", &opc);
	switch(opc)
	{
		case 1:
			opc=1;
			break;
		case 2:
			opc=2;
			break;
		case 3:
			opc=3;
			break;
		default:
			break;	
	}
	while(i<lista->n)
	{
		B = A->siguiente;
		while(B != NULL)
		{
			if(opc == 1)
			{
				if((int)A->primer_nombre[0] > (int)B->primer_nombre[0])
				{
					strcpy(auxiliar.primer_nombre, A->primer_nombre);
					strcpy(auxiliar.segundo_nombre, A->segundo_nombre);
					strcpy(auxiliar.primer_apellido, A->primer_apellido);
					strcpy(auxiliar.segundo_apellido, A->segundo_apellido);
					strcpy(auxiliar.fecha_nacimiento, A->fecha_nacimiento);
					strcpy(auxiliar.curp_generado, A->curp_generado);

					strcpy(A->primer_nombre, B->primer_nombre);
					strcpy(A->segundo_nombre, B->segundo_nombre);
					strcpy(A->primer_apellido, B->primer_apellido);
					strcpy(A->segundo_apellido, B->segundo_apellido);
					strcpy(A->fecha_nacimiento, B->fecha_nacimiento);
					strcpy(A->curp_generado, B->curp_generado);

					strcpy(B->primer_nombre, auxiliar.primer_nombre);
					strcpy(B->segundo_nombre, auxiliar.segundo_nombre);
					strcpy(B->primer_apellido, auxiliar.primer_apellido);
					strcpy(B->segundo_apellido, auxiliar.segundo_apellido);
					strcpy(B->fecha_nacimiento, auxiliar.fecha_nacimiento);
					strcpy(B->curp_generado, auxiliar.curp_generado);
				}
			}
			if(opc==2)
			{
				if((int)A->primer_apellido[0] > (int)B->primer_apellido[0])
				{
					strcpy(auxiliar.primer_nombre, A->primer_nombre);
					strcpy(auxiliar.segundo_nombre, A->segundo_nombre);
					strcpy(auxiliar.primer_apellido, A->primer_apellido);
					strcpy(auxiliar.segundo_apellido, A->segundo_apellido);
					strcpy(auxiliar.fecha_nacimiento, A->fecha_nacimiento);
					strcpy(auxiliar.curp_generado, A->curp_generado);

					strcpy(A->primer_nombre, B->primer_nombre);
					strcpy(A->segundo_nombre, B->segundo_nombre);
					strcpy(A->primer_apellido, B->primer_apellido);
					strcpy(A->segundo_apellido, B->segundo_apellido);
					strcpy(A->fecha_nacimiento, B->fecha_nacimiento);
					strcpy(A->curp_generado, B->curp_generado);

					strcpy(B->primer_nombre, auxiliar.primer_nombre);
					strcpy(B->segundo_nombre, auxiliar.segundo_nombre);
					strcpy(B->primer_apellido, auxiliar.primer_apellido);
					strcpy(B->segundo_apellido, auxiliar.segundo_apellido);
					strcpy(B->fecha_nacimiento, auxiliar.fecha_nacimiento);
					strcpy(B->curp_generado, auxiliar.curp_generado);
				}
			}
			if(opc==3)
			{
				int fecha1, fecha2 ;
				fecha1 = convertir(A->fecha_nacimiento);
				fecha2 = convertir(B->fecha_nacimiento);
				if(fecha1 > fecha2)
				{
					strcpy(auxiliar.primer_nombre, A->primer_nombre);
					strcpy(auxiliar.segundo_nombre, A->segundo_nombre);
					strcpy(auxiliar.primer_apellido, A->primer_apellido);
					strcpy(auxiliar.segundo_apellido, A->segundo_apellido);
					strcpy(auxiliar.fecha_nacimiento, A->fecha_nacimiento);
					strcpy(auxiliar.curp_generado, A->curp_generado);

					strcpy(A->primer_nombre, B->primer_nombre);
					strcpy(A->segundo_nombre, B->segundo_nombre);
					strcpy(A->primer_apellido, B->primer_apellido);
					strcpy(A->segundo_apellido, B->segundo_apellido);
					strcpy(A->fecha_nacimiento, B->fecha_nacimiento);
					strcpy(A->curp_generado, B->curp_generado);

					strcpy(B->primer_nombre, auxiliar.primer_nombre);
					strcpy(B->segundo_nombre, auxiliar.segundo_nombre);
					strcpy(B->primer_apellido, auxiliar.primer_apellido);
					strcpy(B->segundo_apellido, auxiliar.segundo_apellido);
					strcpy(B->fecha_nacimiento, auxiliar.fecha_nacimiento);
					strcpy(B->curp_generado, auxiliar.curp_generado);
				}
			}
			B = B->siguiente;
		}
		A = A->siguiente;
		i++;
	}
	borrar_memoria(&auxiliar);
}

void seleccion(Lista* lista)
{
	if(lista->n==1 || lista->n==0) return;
	Nodo* cabeza;
	Nodo* nodo_ordenar;
	Nodo* aux;
	cabeza = lista->cabeza;
	Curp auxiliar;
	crear(&auxiliar); 
	int opc;
	printf("\nSeleccione el criterio para ordenar las curps:\n1) Primer nombre\n2) Primer apellido\n3) Fecha de nacimiento\nOpcion deseada: ");
	scanf("%d", &opc);
	switch(opc)
	{
		case 1:
			opc=1;
			break;
		case 2:
			opc=2;
			break;
		case 3:
			opc=3;
			break;
		default:
			break;	
	}
	while(cabeza)
	{
		nodo_ordenar = cabeza; 
		aux = nodo_ordenar->siguiente;
		while(aux)
		{
			if(opc==1)
			{
				if((int)aux->primer_nombre[0] < (int)nodo_ordenar->primer_nombre[0])
				nodo_ordenar = aux;
			}
			if(opc==2)
			{
				if((int)aux->primer_apellido[0] < (int)nodo_ordenar->primer_apellido[0])
				nodo_ordenar = aux;
			}
			if(opc == 3)
			{
				int fecha1, fecha2 ;
				fecha1 = convertir(aux->fecha_nacimiento);
				fecha2 = convertir(nodo_ordenar->fecha_nacimiento);
				if(fecha1 < fecha2)
				nodo_ordenar = aux;
			}
			aux = aux->siguiente;
		}
		if(nodo_ordenar != cabeza)
		{
			strcpy(auxiliar.primer_nombre, nodo_ordenar->primer_nombre);
			strcpy(auxiliar.segundo_nombre, nodo_ordenar->segundo_nombre);
			strcpy(auxiliar.primer_apellido, nodo_ordenar->primer_apellido);
			strcpy(auxiliar.segundo_apellido, nodo_ordenar->segundo_apellido);
			strcpy(auxiliar.fecha_nacimiento, nodo_ordenar->fecha_nacimiento);
			strcpy(auxiliar.curp_generado, nodo_ordenar->curp_generado);

			strcpy(nodo_ordenar->primer_nombre, cabeza->primer_nombre);
			strcpy(nodo_ordenar->segundo_nombre, cabeza->segundo_nombre);
			strcpy(nodo_ordenar->primer_apellido, cabeza->primer_apellido);
			strcpy(nodo_ordenar->segundo_apellido, cabeza->segundo_apellido);
			strcpy(nodo_ordenar->fecha_nacimiento, cabeza->fecha_nacimiento);
			strcpy(nodo_ordenar->curp_generado, cabeza->curp_generado);

			strcpy(cabeza->primer_nombre, auxiliar.primer_nombre);
			strcpy(cabeza->segundo_nombre, auxiliar.segundo_nombre);
			strcpy(cabeza->primer_apellido, auxiliar.primer_apellido);
			strcpy(cabeza->segundo_apellido, auxiliar.segundo_apellido);
			strcpy(cabeza->fecha_nacimiento, auxiliar.fecha_nacimiento);
			strcpy(cabeza->curp_generado, auxiliar.curp_generado);
		}
		cabeza = cabeza->siguiente;
	}
	borrar_memoria(&auxiliar);
}

void insercion(Lista* lista)
{
	if(lista->n==1 || lista->n==0) return;
	Nodo* cabeza;
	Nodo* nodo_ordenar;
	Curp auxiliar;
	Curp auxiliar2;
	crear(&auxiliar);
	crear(&auxiliar2); 
	int opc;
	printf("\nSeleccione el criterio para ordenar las curps:\n1) Primer nombre\n2) Primer apellido\n3) Fecha de nacimiento\nOpcion deseada: ");
	scanf("%d", &opc);
	switch(opc)
	{
		case 1:
			opc=1;
			break;
		case 2:
			opc=2;
			break;
		case 3:
			opc=3;
			break;
		default:
			break;	
	}
	nodo_ordenar = lista->cabeza->siguiente;
	while(nodo_ordenar != NULL)
	{
		strcpy(auxiliar.primer_nombre, nodo_ordenar->primer_nombre);
		strcpy(auxiliar.segundo_nombre, nodo_ordenar->segundo_nombre);
		strcpy(auxiliar.primer_apellido, nodo_ordenar->primer_apellido);
		strcpy(auxiliar.segundo_apellido, nodo_ordenar->segundo_apellido);
		strcpy(auxiliar.fecha_nacimiento, nodo_ordenar->fecha_nacimiento);
		strcpy(auxiliar.curp_generado, nodo_ordenar->curp_generado);
		int encontrar=0;
		cabeza = lista->cabeza;
		while(cabeza != nodo_ordenar)
		{
			if (opc == 1)
			{	
				if((int)cabeza->primer_nombre[0] > (int)nodo_ordenar->primer_nombre[0] && encontrar == 0)
				{
					strcpy(auxiliar.primer_nombre, cabeza->primer_nombre);
					strcpy(auxiliar.segundo_nombre, cabeza->segundo_nombre);
					strcpy(auxiliar.primer_apellido, cabeza->primer_apellido);
					strcpy(auxiliar.segundo_apellido, cabeza->segundo_apellido);
					strcpy(auxiliar.fecha_nacimiento, cabeza->fecha_nacimiento);
					strcpy(auxiliar.curp_generado, cabeza->curp_generado);

					strcpy(cabeza->primer_nombre, nodo_ordenar->primer_nombre);
					strcpy(cabeza->segundo_nombre, nodo_ordenar->segundo_nombre);
					strcpy(cabeza->primer_apellido, nodo_ordenar->primer_apellido);
					strcpy(cabeza->segundo_apellido, nodo_ordenar->segundo_apellido);
					strcpy(cabeza->fecha_nacimiento, nodo_ordenar->fecha_nacimiento);
					strcpy(cabeza->curp_generado, nodo_ordenar->curp_generado);

					encontrar = 1;
					cabeza = cabeza->siguiente;	
				}
				else
				{
					if(encontrar == 1)
					{
						strcpy(auxiliar.primer_nombre, auxiliar2.primer_nombre);
						strcpy(auxiliar.segundo_nombre, auxiliar2.segundo_nombre);
						strcpy(auxiliar.primer_apellido, auxiliar2.primer_apellido);
						strcpy(auxiliar.segundo_apellido, auxiliar2.segundo_apellido);
						strcpy(auxiliar.fecha_nacimiento, auxiliar2.fecha_nacimiento);
						strcpy(auxiliar.curp_generado, auxiliar2.curp_generado);

						strcpy(auxiliar.primer_nombre, cabeza->primer_nombre);
						strcpy(auxiliar.segundo_nombre, cabeza->segundo_nombre);
						strcpy(auxiliar.primer_apellido, cabeza->primer_apellido);
						strcpy(auxiliar.segundo_apellido, cabeza->segundo_apellido);
						strcpy(auxiliar.fecha_nacimiento, cabeza->fecha_nacimiento);
						strcpy(auxiliar.curp_generado, cabeza->curp_generado);	
						
						strcpy(cabeza->primer_nombre, auxiliar2.primer_nombre);
						strcpy(cabeza->segundo_nombre, auxiliar2.segundo_nombre);
						strcpy(cabeza->primer_apellido, auxiliar2.primer_apellido);
						strcpy(cabeza->segundo_apellido, auxiliar2.segundo_apellido);
						strcpy(cabeza->fecha_nacimiento, auxiliar2.fecha_nacimiento);
						strcpy(cabeza->curp_generado, auxiliar2.curp_generado);				
					}
					cabeza = cabeza->siguiente;	
				}
			}
			if (opc == 2)
			{	
				if((int)cabeza->primer_apellido[0] > (int)nodo_ordenar->primer_apellido[0] && encontrar == 0)
				{
					strcpy(auxiliar.primer_nombre, cabeza->primer_nombre);
					strcpy(auxiliar.segundo_nombre, cabeza->segundo_nombre);
					strcpy(auxiliar.primer_apellido, cabeza->primer_apellido);
					strcpy(auxiliar.segundo_apellido, cabeza->segundo_apellido);
					strcpy(auxiliar.fecha_nacimiento, cabeza->fecha_nacimiento);
					strcpy(auxiliar.curp_generado, cabeza->curp_generado);

					strcpy(cabeza->primer_nombre, nodo_ordenar->primer_nombre);
					strcpy(cabeza->segundo_nombre, nodo_ordenar->segundo_nombre);
					strcpy(cabeza->primer_apellido, nodo_ordenar->primer_apellido);
					strcpy(cabeza->segundo_apellido, nodo_ordenar->segundo_apellido);
					strcpy(cabeza->fecha_nacimiento, nodo_ordenar->fecha_nacimiento);
					strcpy(cabeza->curp_generado, nodo_ordenar->curp_generado);

					encontrar = 1;
					cabeza = cabeza->siguiente;	
				}
				else
				{
					if(encontrar == 1)
					{
						strcpy(auxiliar.primer_nombre, auxiliar2.primer_nombre);
						strcpy(auxiliar.segundo_nombre, auxiliar2.segundo_nombre);
						strcpy(auxiliar.primer_apellido, auxiliar2.primer_apellido);
						strcpy(auxiliar.segundo_apellido, auxiliar2.segundo_apellido);
						strcpy(auxiliar.fecha_nacimiento, auxiliar2.fecha_nacimiento);
						strcpy(auxiliar.curp_generado, auxiliar2.curp_generado);

						strcpy(auxiliar.primer_nombre, cabeza->primer_nombre);
						strcpy(auxiliar.segundo_nombre, cabeza->segundo_nombre);
						strcpy(auxiliar.primer_apellido, cabeza->primer_apellido);
						strcpy(auxiliar.segundo_apellido, cabeza->segundo_apellido);
						strcpy(auxiliar.fecha_nacimiento, cabeza->fecha_nacimiento);
						strcpy(auxiliar.curp_generado, cabeza->curp_generado);	
						
						strcpy(cabeza->primer_nombre, auxiliar2.primer_nombre);
						strcpy(cabeza->segundo_nombre, auxiliar2.segundo_nombre);
						strcpy(cabeza->primer_apellido, auxiliar2.primer_apellido);
						strcpy(cabeza->segundo_apellido, auxiliar2.segundo_apellido);
						strcpy(cabeza->fecha_nacimiento, auxiliar2.fecha_nacimiento);
						strcpy(cabeza->curp_generado, auxiliar2.curp_generado);				
					}
					cabeza = cabeza->siguiente;	
				}
			}
			if (opc == 3)
			{	
				int fecha1, fecha2;
				fecha1 = convertir(cabeza->fecha_nacimiento);
				fecha2 = convertir(nodo_ordenar->fecha_nacimiento);
				if(fecha1 > fecha2 && encontrar == 0)
				{
					strcpy(auxiliar.primer_nombre, cabeza->primer_nombre);
					strcpy(auxiliar.segundo_nombre, cabeza->segundo_nombre);
					strcpy(auxiliar.primer_apellido, cabeza->primer_apellido);
					strcpy(auxiliar.segundo_apellido, cabeza->segundo_apellido);
					strcpy(auxiliar.fecha_nacimiento, cabeza->fecha_nacimiento);
					strcpy(auxiliar.curp_generado, cabeza->curp_generado);

					strcpy(cabeza->primer_nombre, nodo_ordenar->primer_nombre);
					strcpy(cabeza->segundo_nombre, nodo_ordenar->segundo_nombre);
					strcpy(cabeza->primer_apellido, nodo_ordenar->primer_apellido);
					strcpy(cabeza->segundo_apellido, nodo_ordenar->segundo_apellido);
					strcpy(cabeza->fecha_nacimiento, nodo_ordenar->fecha_nacimiento);
					strcpy(cabeza->curp_generado, nodo_ordenar->curp_generado);

					encontrar = 1;
					cabeza = cabeza->siguiente;	
				}
				else
				{
					if(encontrar == 1)
					{
						strcpy(auxiliar.primer_nombre, auxiliar2.primer_nombre);
						strcpy(auxiliar.segundo_nombre, auxiliar2.segundo_nombre);
						strcpy(auxiliar.primer_apellido, auxiliar2.primer_apellido);
						strcpy(auxiliar.segundo_apellido, auxiliar2.segundo_apellido);
						strcpy(auxiliar.fecha_nacimiento, auxiliar2.fecha_nacimiento);
						strcpy(auxiliar.curp_generado, auxiliar2.curp_generado);

						strcpy(auxiliar.primer_nombre, cabeza->primer_nombre);
						strcpy(auxiliar.segundo_nombre, cabeza->segundo_nombre);
						strcpy(auxiliar.primer_apellido, cabeza->primer_apellido);
						strcpy(auxiliar.segundo_apellido, cabeza->segundo_apellido);
						strcpy(auxiliar.fecha_nacimiento, cabeza->fecha_nacimiento);
						strcpy(auxiliar.curp_generado, cabeza->curp_generado);	
						
						strcpy(cabeza->primer_nombre, auxiliar2.primer_nombre);
						strcpy(cabeza->segundo_nombre, auxiliar2.segundo_nombre);
						strcpy(cabeza->primer_apellido, auxiliar2.primer_apellido);
						strcpy(cabeza->segundo_apellido, auxiliar2.segundo_apellido);
						strcpy(cabeza->fecha_nacimiento, auxiliar2.fecha_nacimiento);
						strcpy(cabeza->curp_generado, auxiliar2.curp_generado);				
					}
					cabeza = cabeza->siguiente;	
				}
			}
		}
		strcpy(cabeza->primer_nombre, auxiliar.primer_nombre);
		strcpy(cabeza->segundo_nombre, auxiliar.segundo_nombre);
		strcpy(cabeza->primer_apellido, auxiliar.primer_apellido);
		strcpy(cabeza->segundo_apellido, auxiliar.segundo_apellido);
		strcpy(cabeza->fecha_nacimiento, auxiliar.fecha_nacimiento);
		strcpy(cabeza->curp_generado, auxiliar.curp_generado);		
		nodo_ordenar = nodo_ordenar->siguiente;
	}
	borrar_memoria(&auxiliar);
	borrar_memoria(&auxiliar2);
}

void curp(unsigned opc_cri, unsigned opc_alg)
{
	Curp datos;
	Lista* lista=NULL;
	int numero_curps=0, opc;
	printf("Numero de curps que desea ingresar(Ingresar todos de una vez): ");
	scanf("%d", &numero_curps);
	if(numero_curps == 0) return;
	crear(&datos);
	for(int i=0; i<numero_curps; i++)
	{
		obtener_datos(&datos);
		generar_curp(&datos);
		agregar_nodo(&lista, &datos);
	}
	do
	{
		printf("\nMENU DE OPCIONES\n");
		printf("1. Ordenamiento burbuja\n2. Ordenamiento seleccion\n 3. Ordenamiento insercion\n4. Busqueda secuencial\n5. Busqueda binaria\n6. Busqueda\n7. Imprimir lista\n 8.Salir");
		printf("\nOpcion deseada: ");
		scanf("%d", &opc);
		switch(opc)
		{
			case 1:
				burbuja(lista);
				break;
			case 2:
				seleccion(lista);
				break;
			case 3:
				insercion(lista);
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				imprimir_lista(lista);
				break;	
			case 8:
				break;
		}
	} while(opc != 8);
	liberar_lista(lista);
	borrar_memoria(&datos);
}