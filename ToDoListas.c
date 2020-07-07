#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
typedef struct Tarea{
	int tareaId;
	char *desc;
	int duracion;
	int realizada;
}Tarea;
typedef struct Nodo{
	Tarea tarea;
	struct Nodo *siguiente;
}Nodo;
char desc[6][20] = {"Cargar Precio","Verificar Stock","Listar Vencidos","Proximos a vencer","Mas vendidos","Menos vendidos"};
//prototipos
Nodo *crearListaVacia();
Tarea crearTarea(int _tareaId, char *_desc, int _duracion, int _realizada);
Nodo *crearNodo(Tarea TAux);
void InsertarNodoALaLista(Nodo **listaTotal, Nodo *NNodo);
void mostarLista(Nodo *listaTotal);
void mostrarLista(Nodo *listaTotal);
void distribuirListas(Nodo **listaTotal, Nodo **listaRealizada, Nodo **listaPendiente);
Nodo * QuitarNodoDeLaLista(Nodo **listaTotal);
void buscarTareaPorId(Nodo *listaPendiente, Nodo *listaRealizada, int id);
void buscarTareaPorClave(Nodo *listaPendiente, Nodo *listaRealizada);

int main(){																					//MAIN
	srand(time(0));
	Nodo *listaTotal = crearListaVacia();
	Nodo *listaPendiente = crearListaVacia();
	Nodo *listaRealizada = crearListaVacia();
	Tarea TAux;
	Nodo *NNodo;
	int _tareaId;
	
	for(int i = 0; i < 10; i++){
		TAux = crearTarea(i+1, desc[rand() %5], ((rand() %100) + 10), (rand() % 2));
		NNodo = crearNodo(TAux);
		InsertarNodoALaLista(&listaTotal, NNodo);		
	}
	distribuirListas(&listaTotal,&listaRealizada,&listaPendiente);
	printf("--- Lista Pendiente ---\n\n");
	mostrarLista(listaPendiente);
	printf("\n\n--- Lista Realizada ---\n\n");
	mostrarLista(listaRealizada);
	printf("\n\nBUSCAR TAREA!!! Ingrese el id de la tarea a buscar: ---\n\n");
	scanf("%d", &_tareaId);fflush(stdin);
	buscarTareaPorId(listaPendiente, listaRealizada, _tareaId);
	buscarTareaPorClave(listaPendiente, listaRealizada);
	return 0;
}
//funciones
void buscarTareaPorClave(Nodo *listaPendiente, Nodo *listaRealizada){
	char claveTarea[30];
	printf("\n\nBUSCAR TAREA!!! Ingrese el nombre clave de la tarea: ---\n\n");
	gets(claveTarea);	
	while(listaPendiente != NULL){
		if(strcmp(listaPendiente->tarea.desc, claveTarea) == 0){
			printf("\n ----	TAREA ENCONTRADA POR CLAVE!	----");
			printf("\nID: %d", listaPendiente->tarea.tareaId);
			printf("\nDESCRIPCION: %s", listaPendiente->tarea.desc);
			printf("\nDURACION: %d", listaPendiente->tarea.duracion);
			if(listaPendiente->tarea.realizada == 1){
				printf("\nESTADO: Realizada");
			}else{
				printf("\nESTADO: No Realizada");
			}
			printf("\n --------------------  ");
			break;
		}
		listaPendiente = listaPendiente->siguiente;
	}
	while(listaRealizada != NULL){
		if(strcmp(listaRealizada->tarea.desc, claveTarea) == 0){
			printf("\n ----------	TAREA ENCONTRADA POR CLAVE!	----------  ");
			printf("\nID: %d", listaRealizada->tarea.tareaId);
			printf("\nDESCRIPCION: %s", listaRealizada->tarea.desc);
			printf("\nDURACION: %d", listaRealizada->tarea.duracion);
			if(listaRealizada->tarea.realizada == 1){
				printf("\nESTADO: Realizada");
			}else{
				printf("\nESTADO: No Realizada");
			}
			printf("\n --------------------  ");
			break;
		}
		listaRealizada = listaRealizada->siguiente;
	}
		
}
void buscarTareaPorId(Nodo *listaPendiente, Nodo *listaRealizada, int id){
	while(listaPendiente != NULL){
		if(listaPendiente->tarea.tareaId == id){
			printf("\n ----	TAREA ENCONTRADA POR ID!	----");
			printf("\nID: %d", listaPendiente->tarea.tareaId);
			printf("\nDESCRIPCION: %s", listaPendiente->tarea.desc);
			printf("\nDURACION: %d", listaPendiente->tarea.duracion);
			if(listaPendiente->tarea.realizada == 1){
				printf("\nESTADO: Realizada");
			}else{
				printf("\nESTADO: No Realizada");
			}
			printf("\n --------------------  ");
		}
		listaPendiente = listaPendiente->siguiente;
	}
	while(listaRealizada != NULL){
		if(listaRealizada->tarea.tareaId == id){
			printf("\n ----------	TAREA ENCONTRADA POR ID!	----------  ");
			printf("\nID: %d", listaRealizada->tarea.tareaId);
			printf("\nDESCRIPCION: %s", listaRealizada->tarea.desc);
			printf("\nDURACION: %d", listaRealizada->tarea.duracion);
			if(listaRealizada->tarea.realizada == 1){
				printf("\nESTADO: Realizada");
			}else{
				printf("\nESTADO: No Realizada");
			}
			printf("\n --------------------  ");
		}
		listaRealizada = listaRealizada->siguiente;
	}
}
void distribuirListas(Nodo **listaTotal, Nodo **listaRealizada, Nodo **listaPendiente){
	Nodo *Aux;
	while(*listaTotal != NULL){
		//obtener el nodo de la cabecera
		Aux = QuitarNodoDeLaLista(listaTotal);
		//comparar el campo
		if(Aux->tarea.realizada == 1){
			InsertarNodoALaLista(listaRealizada, Aux);
		}else{
			InsertarNodoALaLista(listaPendiente, Aux);
		}
	}
}
Nodo * QuitarNodoDeLaLista(Nodo **listaTotal){//saca un nodo de la lista en particular, y devuelve el nodo para que trabajemos. esto se repite n veces
	Nodo *Aux = *listaTotal;// A aux lo hace apuntar a &lista como es un puntero doble solo nos interesa recorrerlo, por eso el *lista
	if(*listaTotal != NULL){
		*listaTotal = (*listaTotal)->siguiente;
		Aux->siguiente = NULL;//a cada nodo retirado, lo dejamos apuntando a null como uno independiente
	}return Aux;
}
void mostrarLista(Nodo *listaTotal){
	while(listaTotal != NULL){
		printf("\nID: %d", listaTotal->tarea.tareaId);
		printf("\nDESCRIPCION: %s", listaTotal->tarea.desc);
		printf("\nDURACION: %d", listaTotal->tarea.duracion);
		if(listaTotal->tarea.realizada == 1){
			printf("\nESTADO: Realizada");
		}else{
			printf("\nESTADO: No Realizada");
		}
		
		printf("\n --------------------  ");
		listaTotal = listaTotal->siguiente;
	}
}
void InsertarNodoALaLista(Nodo **listaTotal, Nodo *NNodo){
	NNodo->siguiente = *listaTotal;
	*listaTotal = NNodo;
}
Nodo *crearNodo(Tarea TAux){
	Nodo *NAux = (Nodo *)malloc(sizeof(Nodo));
	NAux->tarea.tareaId = TAux.tareaId;
	NAux->tarea.desc = TAux.desc;
	NAux->tarea.duracion = TAux.duracion;
	NAux->tarea.realizada = TAux.realizada;
	NAux->siguiente = NULL;
	return NAux;
	
}
Tarea crearTarea(int _tareaId, char *_desc, int _duracion, int _realizada){
	Tarea TAux;
	TAux.tareaId = _tareaId;
	TAux.desc = _desc;
	TAux.duracion = _duracion;
	TAux.realizada = _realizada;
	
	return TAux;
}
Nodo * crearListaVacia(){
	return NULL;
}
