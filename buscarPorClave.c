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
