#include<stdio.h>

//saving the value of recursive point
int memo[1000] = {0};

//fibonaci with memoization
int fibMemooization(int n){
    //base case
    if(n <= 1) return 1;

    //memoization
    if(memo[n] != 0) return memo[n];

    //recursvie
    return memo[n] = fibMemooization(n - 1) +  fibMemooization(n - 2);

}


//normal fibonaci
int fib(int n){
    //base case
    if(n <= 1) return 1;

    //recursive 
    return fib(n - 1) + fib(n - 2);
}


int main(){

    int n;
    scanf("%d", &n); 
    getchar();

    //array to store
    int tabulation[1000] = {0};
    tabulation[0] = tabulation [1] = 1;

    //tabulation
    for(int i=2; i<=n; i++){
        tabulation[i] = tabulation[i - 1] + tabulation[i - 2];
    }

    printf("%d", tabulation[n]);


    return 0;
}