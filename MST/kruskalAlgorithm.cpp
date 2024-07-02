#include<stdio.h>
#include<stdlib.h>

#define ed 5
#define ver 4

struct Edges{
    int dest;
    int src;
    int cost;
}edge[ed];

void bubleSort(){
    for(int i=0; i<ed; i++){
        for(int j=0; j<ed - i - 1; j++){
            if(edge[j].cost > edge[j+1].cost){
                Edges temp = edge[j];
                edge[j] = edge[j+1];
                edge[j+1] = temp;
            }
        }
    }
    return;
}

int findParent(int *listPath, int idx){
    if(listPath[idx] == idx){
        return idx;
    }
    return findParent(listPath, listPath[idx]);
}

void unionParent(int *listPath, int idx1, int idx2){
    listPath[findParent(listPath, idx1)] = findParent(listPath, idx2);
}

void kruskal(int v, int e){
    bubleSort();

    //Initialization parent
    int listPath[ver];
    for(int i=0; i<ver; i++) listPath[i] = i;

    //Intialization result
    int indexResult = 0;
    int indexEdge = 0;

    while(indexResult < v-1){
        Edges currEdge = edge[indexEdge];
        indexEdge++;

        int parent1 = findParent(listPath, currEdge.src);
        int parent2 = findParent(listPath, currEdge.dest);

        if(parent1 != parent2){
            edge[indexResult] = currEdge;
            indexResult++;
            unionParent(listPath, parent1, parent2);
        }

    }
}

void viewPath(){
    for(int i=0; i<ver-1; i++){
        printf("%d - %d = %d\n", edge[i].src, edge[i].dest, edge[i].cost);
    }
}

int main(){

    edge[0] = {0, 1, 10};
    edge[1] = {0, 2, 6};
    edge[2] = {0, 3, 5};
    edge[3] = {1, 3, 15};
    edge[4] = {2, 3, 4};

    kruskal(ver, ed);
    viewPath();

    return 0;
}