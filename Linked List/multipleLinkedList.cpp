#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
    char stationName[51];
    bool visited; 
    Data *north, *south, *east, *west;
}*root = NULL;

Data* createData(char stationName[]){
    Data* newData = (Data*)malloc(sizeof(Data));
    strcpy(newData->stationName, stationName);
    bool visited = false;
    newData->west = newData->east = newData->south = newData->north = NULL;

    return newData;
}

void pushNorth(Data *temp, char name[]) {
    if (temp->north) return;
    Data *newData = createData(name);
    newData->south = temp;
    temp->north = newData;
}

void pushSouth(Data *temp, char name[]) {
    if (temp->south) return;
    Data* newData = createData(name);
    newData->north = temp;
    temp->south = newData;
}

void pushEast(Data *temp, char name[]) {
    if (temp->east) return;
    Data* newData = createData(name);
    newData->west = temp;
    temp->east = newData;
}

void pushWest(Data *temp, char name[]) {
    if (temp->west) return;
    Data* newData = createData(name);
    newData->east = temp;
    temp->west = newData;
}

void joinWestEast(Data *west, Data *east) {
    west->east = east;
    east->west = west;
}

void joinSouthNorth(Data *south, Data *north) {
    south->north = north;
    north->south = south;
}

void view(Data *temp) {
    if(!temp) return;
    temp->visited = true;
    printf("Station: %s\n", temp->stationName);

    if(temp->north && !temp->north->visited){
        view(temp->north);
    }
    if(temp->south && !temp->south->visited){
        view(temp->south);
    }
    if(temp->east && !temp->east->visited){
        view(temp->east);
    }
    if(temp->west && !temp->west->visited){
        view(temp->west);
    }
}

int main() {
    // Initialize root
    root = createData("0 0");
    pushNorth(root, "0 1");
    pushSouth(root, "0 -1");
    pushEast(root, "1 0");
    pushWest(root, "-1 0");
    pushEast(root->south, "1 -1");
    pushSouth(root->south, "0 -2");

    joinSouthNorth(root->east, root->south->east);

    view(root);

    return 0;
}
