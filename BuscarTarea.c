void buscarPorId(Tarea **tareasPendientes, Tarea **tareasRealizadas, int id, int cant);

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
