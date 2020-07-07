#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct Tarea {
	int tareaID; //Numerado en ciclo iterativo
	char *desc; //
	int duracion; // entre 10 – 100
}Tarea;
char descripcion[5][12] = {"administrar","borrar","contar","deshacer","fijar"};


void cargarTareas(Tarea **tareasT, int cant);
int mostrarTareas(Tarea **tareasT, int cant);
void controlTareas(Tarea **tareasPendientes, Tarea **tareasRealizadas, int cant);
void cargarTareasVacias(Tarea **tareasTR, int cant);
void buscarPorId(Tarea **tareasPendientes, Tarea **tareasRealizadas, int id, int cant);
void buscarPorDesc(Tarea **tareasRealizadas,Tarea **tareasPendientes, int cant);

int main(){
	srand(time(NULL));
	int cant, cond, cant_realizada, cant_pendiente,id;
	cond = 0;
	
	printf("__MENU__\n");
	printf("Ingrese la cantidad de tareas: ");scanf("%d", &cant);fflush(stdin);
	Tarea **tareasPendientes = (Tarea **) malloc(sizeof(Tarea*)*cant);
	Tarea **tareasRealizadas = (Tarea **) malloc(sizeof(Tarea*)*cant);
	cargarTareas(tareasPendientes, cant);
	cargarTareasVacias(tareasRealizadas, cant);
	mostrarTareas(tareasPendientes, cant);
	do{
		printf("\n1 CONTROLAR TAREAS\n2 BUSCAR POR ID\n3 BUSCAR POR DESCRIPCION:  ");
		scanf("%d", &cond);fflush(stdin);
		if(cond == 1){
			controlTareas(tareasPendientes, tareasRealizadas, cant);
			printf("\n***************TAREAS REALIZADAS ***************\n");
			cant_realizada = mostrarTareas(tareasRealizadas, cant);
			printf("\n***************TAREAS PENDIENTES ***************\n");
			cant_pendiente = mostrarTareas(tareasPendientes, cant);
			printf("\nPENDIENTES: %d REALIZADAS: %d\n", cant_pendiente, cant_realizada);
		}else if(cond == 2){
			printf("INGRESE ID A BUSCAR: ");
			scanf("%d", &id);fflush(stdin);
			buscarPorId(tareasRealizadas, tareasPendientes , id,cant);
		}else if(cond == 3){
			buscarPorDesc(tareasRealizadas, tareasPendientes, cant);
		}
	}while(cond != 0);
}
void buscarPorDesc(Tarea **tareasRealizadas,Tarea **tareasPendientes, int cant){
	char aux[20];
	char aux2[20];
	printf("\nINGRESE PALABRA CLAVE: ");gets(aux);
	for(int i = 0; i < 20; i++){
		aux2[i] = tolower(aux[i]);
	}
	
	for(int a = 0; a < cant; a++){
		if(tareasRealizadas[a] != NULL){
			if(strcmp(tareasRealizadas[a]->desc, aux2) == 0){
				printf("Se encontro la tarea %s (Realizada)", tareasRealizadas[a]->desc);
			}
		}
	}
	
	for(int c = 0; c < cant; c++){
		if(tareasPendientes[c] != NULL){
			if(strcmp(tareasPendientes[c]->desc, aux2) == 0){
				printf("Se encontro la tarea %s (Pendiente)", tareasPendientes[c]->desc);
			}
		}
	}
	//printf("PALABRA CLAVE: %s ", aux2);
}
void buscarPorId(Tarea **tareasPendientes, Tarea **tareasRealizadas, int id, int cant){
	
	for(int i = 0; i < cant; i++){
		if(tareasRealizadas[i] != NULL){
			if(tareasRealizadas[i]->tareaID == id){
				printf("Se encontro la tarea %s (Realizada) por ID: %d", tareasRealizadas[i]->desc, tareasRealizadas[i]->tareaID);
			}
		}
	}
	
	for(int c = 0; c < cant; c++){
		if(tareasPendientes[c] != NULL){
			if(tareasPendientes[c]->tareaID == id){
				printf("Se encontro la tarea %s (Pendiente) por ID: %d", tareasPendientes[c]->desc, tareasPendientes[c]->tareaID);
			}
		}
	}
}
void controlTareas(Tarea **tareasPendientes, Tarea **tareasRealizadas, int cant){
	int cond = 0;
	
	for(int i = 0; i < cant; i++){
		printf("Tarea: %s , ID: %d: se realizo?\n 1 si - 2 no\n", tareasPendientes[i]->desc, tareasPendientes[i]->tareaID);
		scanf("%d", &cond);fflush(stdin);
		
		while(cond != 1 && cond != 2){
			printf("Se realizo mal la entrada\n");
			printf("Tarea: %s , ID: %d: se realizo?\n 1 si - 2 no\n", tareasPendientes[i]->desc, tareasPendientes[i]->tareaID);
			scanf("%d", &cond);fflush(stdin);
		}
		if(cond == 1){
			//tareasTR[i] = (Tarea *)malloc(sizeof(Tarea));
			tareasRealizadas[i] = tareasPendientes[i];
			tareasPendientes[i] = NULL;
		}else {
			tareasRealizadas[i] = NULL;
		}
	}
}

void cargarTareasVacias(Tarea **tareasTR, int cant){
	for(int i = 0; i < cant; i++){
		tareasTR[i] = (Tarea *)malloc(sizeof(Tarea));
	}
}
void cargarTareas(Tarea **tareasT, int cant){
	for(int i = 0; i < cant; i++){
		tareasT[i] = (Tarea *)malloc(sizeof(Tarea));
		tareasT[i]->tareaID = i+1;
		tareasT[i]->duracion = (rand()%90 + 10);
		tareasT[i]->desc = descripcion[rand()%5];
	}
}
int mostrarTareas(Tarea **tareasT, int cant){
	int cantAux = 0;
	for(int i = 0; i<cant; i++){
		if(tareasT[i] != NULL){
			printf("\nID: %d", tareasT[i]->tareaID);
			printf("\nDUR: %d", tareasT[i]->duracion);
			printf("\nDESC: %s", tareasT[i]->desc);
			printf("\n**************\n");
			cantAux++;
		}
	}
	return cantAux;
}
