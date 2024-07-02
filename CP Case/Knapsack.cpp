#include<stdio.h>

int max(int a, int b){
    return a > b ? a : b;
}

int main(){

    int maxWeight;
    int items[4];
    int values[4];

    scanf("%d", &maxWeight);
    getchar();

    for(int i=0; i<4; i++){
        scanf("%d", &items[i]);
    }
    getchar();

    for(int i=0; i<4; i++){
        scanf("%d", &values[i]);
    }
    getchar();

    int itemLen = sizeof(items) / sizeof(items[0]);
    int ans[maxWeight+1];

    for(int i=0; i<=maxWeight; i++){
        ans[i] = 0;
    }

    // Dynamic programming approach to solve knapsack
    for(int j=0; j<itemLen; j++){
        for(int i=maxWeight; i>=items[j]; i--){
            ans[i] = max(ans[i], ans[i - items[j]] + values[j]);
        }
    }
    
    printf("%d", ans[maxWeight]);

    return 0;
}