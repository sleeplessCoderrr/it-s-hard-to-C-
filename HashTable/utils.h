//Menu
void main_menu(){
    printf("\t--------------------\n");
    printf("\t| Aircraft Manager |\n");
    printf("\t--------------------\n");
    printf("\t1. Insert Aircraft\n");
    printf("\t2. View Aircraft\n");
    printf("\t3. Delete Aircraft\n");
    printf("\t4. Exit\n");
    printf("\t[ >> ]: ");
}

//Validation
bool is_valid_type(char *type){
    if(strcmp(type, "Cargo") == 0 || strcmp(type, "Passenger") == 0) return true;
    return false;
}

bool is_valid_destination_code(char *dest_code){
    if(strcmp(dest_code, "LAX") == 0 || strcmp(dest_code, "CDG") == 0 || strcmp(dest_code, "JFK") == 0) return true;
    return false;
}

bool is_valid_priority_level(int priority_level){
    if(priority_level >= 1 && priority_level <= 3) return true;
    return false;
}

bool is_valid_id(char *id){
    for(int i=0; i<SIZE; i++){
        if(!head[i]) continue;
        Aircraft* curr = head[i];
        while(curr){
            if(strcmp(curr->id, id) == 0) return true;
            curr = curr->next;
        }
    }
    return false;
}