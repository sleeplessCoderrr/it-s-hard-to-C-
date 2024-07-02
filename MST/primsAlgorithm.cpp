#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define V 5

//Continue too looping and find the minimum cost exist and not visited
int minValue(int cost[], bool visited[]){
    int min = INT_MAX;
    int min_Index;

    for(int i=0; i<V; i++){
        if(visited[i] == false && cost[i] < min){
            min = cost[i];
            min_Index = i;
        }
    }
    return min_Index;
}

void printMST(int parent[], int graph[V][V]){
    printf("Edge \tWeight\n");
    for(int i=1; i<V; i++){
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[V][V]){
    int parent[V];
    int cost[V];
    bool visited[V];

    for(int i=0; i<V; i++){
        cost[i] = INT_MAX;
        visited[i] = false;
    }

    cost[0] = 0;
    parent[0] = -1;

    for(int i=0; i<V-1; i++){
        int u = minValue(cost, visited);
        visited[u] = true;

        for(int v=0; v<V; v++){
            if(graph[u][v] && visited[v] == false && graph[u][v] < cost[v]){
                parent[v] = u;
                cost[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}


int main(){

    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    return 0;
}