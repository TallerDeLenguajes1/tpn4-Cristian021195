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
