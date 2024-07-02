#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 8

struct Data{
    int age;
    char name[56];
}*table[SIZE];

int hashing(char name[]){
	return (name[0] - 'A') % SIZE;
}

Data* createData(int age, char name[]){
    Data* newData = (Data*)malloc(sizeof(Data));
    newData->age = age;
    strcpy(newData->name, name);
    
    return newData;
}

void pushData(Data* newData){
	int index = hashing(newData->name);
	if(!table[index]){
		table[index]= newData;
		return;
	} else {
		int count = 0;
		while(table[index]){
			index++;
			index %= SIZE;
			count++;
			if(count >= SIZE) return;
		}
		table[index] = newData;
		return;
	}
	return;
}

void deleteData(char name[]){
	int index = hashing(name);
	if(strcmp(table[index]->name, name) == 0){
		free(table[index]);
		table[index] = NULL;
		return;
	} else {
		int count = 0;
		while(strcmp(table[index]->name, name) != 0){
			index++;
			index %= SIZE;
			count++;
			if(count >= SIZE) return;
		}
		free(table[index]);
		table[index] = NULL;
		return;
	}
	return;
}

void viewData(){
	for(int i=0; i<SIZE; i++){
		if(!table[i]) continue;
		printf("%d. %s | %d\n",i, table[i]->name, table[i]->age);
	}
	return;
}

int main(){
	pushData(createData(19, "Cece"));
	pushData(createData(19, "Bebek"));
	pushData(createData(19, "Cucu"));
	deleteData("Caca");
	
	viewData();

    return 0;
}
