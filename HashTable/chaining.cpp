#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 26

struct Data{
    int age;
    char name[56];
    Data* next;
    Data* prev;
}*head[SIZE], *tail[SIZE];

int hashing(char name[]){
	return (name[0] - 'A') % SIZE;
}

Data* createData(int age, char name[]){
    Data* newData = (Data*)malloc(sizeof(Data));
    newData->age = age;
    strcpy(newData->name, name);
    newData->prev = newData->next = NULL;
    
    return newData;
}

void pushData(Data* newData){
	int idx = hashing(newData->name);
	if(!head[idx]){
		head[idx] = tail[idx] = newData;
		return;
	} else {
		tail[idx]->next = newData;
		newData->prev = tail[idx];
		tail[idx] = newData;
		return;
	}
}

void deleteData(char name[]){
	int idx = hashing(name);
	
	if(strcmp(head[idx]->name, name) == 0 && strcmp(tail[idx]->name, name) == 0){
		free(head[idx]);
		head[idx] = tail[idx] = NULL;
		return;
	}
	
	if(strcmp(head[idx]->name, name) == 0){
		if(!head[idx]->next){
			free(head[idx]);
			head[idx] = NULL;
			return;
		} else {
			Data* temp = head[idx];
			head[idx] = head[idx]->next;
			head[idx]->prev = NULL;
			free(temp);
			temp = NULL;
			return;
		}
	}
	
	if(strcmp(tail[idx]->name, name) == 0){
		if(!tail[idx]->prev){
			free(tail[idx]);
			tail[idx] = NULL;
			return;
		} else {
			Data* temp = tail[idx];
			tail[idx] = tail[idx]->prev;
			tail[idx]->next = NULL;
			free(temp);
			temp = NULL;
			return;
		}
	}
	
	Data* curr = head[idx];
	while(curr){
		if(strcmp(curr->name, name) == 0){
			Data* temp = curr;
			temp->prev->next = temp->next;
			temp->prev = temp->prev;
			free(temp);
			temp = NULL;
			return;
		}
		curr = curr->next;
	}
	return;
}

void viewData(){
	for(int i=0; i<SIZE; i++){
		if(!head[i]) continue;
		Data* curr = head[i];
		while(curr){
			printf(" <- |%s %d| -> ",curr->name, curr->age);
			curr = curr->next;
		}
		printf("\n");	
	}
}

int main(){
	puts("Before: ");
	pushData(createData(19, "Aur"));
	pushData(createData(19, "Caca"));
	pushData(createData(19, "Cay"));
	pushData(createData(19, "Cla"));
	pushData(createData(19, "Cal"));
	pushData(createData(19, "Calr"));
	viewData();
	puts("");
	deleteData("Calr");
	puts("After: ");
	viewData();
	
	
	
	return 0;
}
