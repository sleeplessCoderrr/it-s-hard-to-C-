struct Aircraft{
	char id[6];
	char type[25];
	char dest_code[4];
	int priority_level;
	int travel_time;
	
	Aircraft* next;
	Aircraft* prev;
}*head[SIZE] = {NULL}, *tail[SIZE] = {NULL};

int get_hash_value(char *id){
	int hash = 0;
	int number = 1;
	int alpha = 1;
	
	for(int i=0; i<strlen(id); i++){
		if(i < 2){
			hash += (id[i] - 'A') * alpha;
			alpha++;
		} else {
			hash += (id[i] - '0') * number;
			number++;
		}
	}
	
	return hash % SIZE;
}

void generate_id(char *id){
	id[0] = 'A' + (rand() % 26);
	id[1] = 'A' + (rand() % 26);
	id[2] = '0' + (rand() % 10);
	id[3] = '0' + (rand() % 10);
	id[4] = '0' + (rand() % 10);
	id[5] = '\0';
}

Aircraft* create_data(char *type, char *dest_code, int priority_level, int travel_time){
	Aircraft* newAircraft = (Aircraft*)malloc(sizeof(Aircraft));
	char id[6];
	generate_id(id);
	
	strcpy(newAircraft->id, id);
	strcpy(newAircraft->type, type);
	strcpy(newAircraft->dest_code, dest_code);
	newAircraft->priority_level = priority_level;
	newAircraft->travel_time = travel_time;
	newAircraft->next = newAircraft->prev = NULL;
	
	return newAircraft;
}

void insert_aircraft(Aircraft* newAircraft){
	int idx = get_hash_value(newAircraft->id);
	
	if(!head[idx]){
		head[idx] = tail[idx] = newAircraft;
		return;
	} else {
		tail[idx]->next = newAircraft;
		newAircraft->prev = tail[idx];
		tail[idx] = newAircraft;
		return;
	}
}

void view_aircraft() {
    int count = 0;
    printf("\t==========================================================================\n");
    printf("\t| %-5s | %-16s | %-10s | %-15s | %-12s |\n", 
           "ID", "Destination Code", "Type", "Priority Level", "Travel Time");
    printf("\t==========================================================================\n");
    
    for (int i = 0; i < SIZE; i++) {
        if (!head[i]) continue;
        Aircraft* curr = head[i];
        while (curr) {
            printf("\t| %-5s | %-16s | %-10s | %-15d | %-12d |\n", 
                   curr->id, curr->dest_code, curr->type, curr->priority_level, curr->travel_time);
            curr = curr->next;
            count++;
        }
    }

    if(count == 0) 
	printf("\t|                           No data available.                           |\n");
    printf("\t==========================================================================\n");
}


void delete_aircraft(char *id){
	int idx = get_hash_value(id);

	if(strcmp(head[idx]->id, id) == 0 && strcmp(tail[idx]->id, id) == 0){
		free(head[idx]);
		head[idx] = tail[idx] = NULL;
		return;
	}
	
	if(strcmp(head[idx]->id, id) == 0){
		if(!head[idx]->next){
			free(head[idx]);
			head[idx] = NULL;
			return;
		}
		
		Aircraft* temp = head[idx];
		head[idx] = head[idx]->next;
		head[idx]->prev = NULL;
		free(temp);
		temp = NULL;
		return;
	}
	
	if(strcmp(tail[idx]->id, id) == 0){
		if(!tail[idx]->prev){
			free(tail[idx]);
			tail[idx] = NULL;
			return;
		}
		
		Aircraft* temp = tail[idx];
		tail[idx] = tail[idx]->prev;
		tail[idx]->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
	
	Aircraft* curr = head[idx];
	while(curr){
		if(strcmp(curr->id, id) == 0){
			Aircraft* temp = curr;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
			temp = NULL;
			return;
		}
		curr = curr->next;
	}
	
	return;
}