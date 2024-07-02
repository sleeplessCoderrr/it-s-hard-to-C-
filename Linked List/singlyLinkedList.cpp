#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Data{
    int age;
    char name[51];
    Data* next;
}*head = NULL, *tail = NULL;

Data* createData(char name[], int age){
    Data* newData = (Data*)malloc(sizeof(Data));
    newData->age = age;
    strcpy(newData->name, name);
    newData->next = NULL;

    return newData;
}

void pushHead(Data* newData){
    if(!head){
        head = tail = newData;
        return;
    }

    newData->next = head;
    head = newData;
    return;
}

void pushTail(Data* newData){
    if(!head){
        head = tail = newData;
        return;
    }

    tail->next = newData;
    tail = newData;
    return;
}

void pushMid(Data* newData){
    if(!head){
        head = tail = newData;
        return;
    } else {
        if(head->age >= newData->age){
            pushHead(newData);
            return;
        } else if(tail->age <= newData->age){
            pushTail(newData);
            return;
        } else {
            Data* curr = head;
            while(curr->next){
                if(curr->next->age >= newData->age){
                    newData->next = curr->next;
                    curr->next = newData;
                    return;
                }
                curr = curr->next;
            }
        }
    }
    return;
}

void popHead(){
    if(!head) return;
    if(head == tail){
        free(head);
        head = NULL;
        return;
    }

    Data* curr = head;
    head = head->next;
    free(curr);
    curr = NULL;
    return;
}

void popTail(){
    if(!head) return;
    if(head == tail){
        free(head);
        head = NULL;
        return;
    }

    Data* curr = head;
    while(curr->next != tail){
        curr = curr->next;
    }
    free(tail);
    tail = curr;
    tail->next = NULL;
}

void popMid(char name[]){
    if(!head) return;
    if(strcmp(head->name, name) == 0){
        popHead();
        return;
    } else if(strcmp(tail->name, name) == 0){
        popTail();
        return;
    } else {
        Data* curr = head;
        while(curr->next != tail){
            if(strcmp(curr->next->name, name) == 0){
                Data* temp = curr->next;
                curr->next = temp->next;
                free(temp);
                temp = NULL;
                return;
            }
            curr = curr->next;
        }
    }
}

void printData(){
    Data* curr = head;
    while(curr){
        printf("%s | %d -> ", curr->name, curr->age);
        curr = curr->next;
    }
}

int main(){
    printf("Before: ");
    pushMid(createData("Bebe", 19));
    pushMid(createData("Cece", 18));
    pushMid(createData("Keke", 17));
    pushMid(createData("Caca", 20));
    pushMid(createData("Jeje", 20));
    pushMid(createData("Meme", 24));
    pushMid(createData("Nene", 16));
    printData();
    puts("");
    printf("After: ");
    popMid("Nene");
    popMid("Meme");
    popMid("Caca");
    printData();
    return 0;
}