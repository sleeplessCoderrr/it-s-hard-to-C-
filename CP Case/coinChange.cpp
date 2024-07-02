#include <stdio.h>

// Function to find the minimum of two numbers
int min(int a, int b) {
    return a < b ? a : b;
}

int main() { 
    int money;
    int coins[4];

    // Scanning the money to change
    printf("Enter the amount of money: ");
    scanf("%d", &money);
    getchar();

    // Scanning the coin options
    printf("Enter the coin: ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &coins[i]);
    }
    getchar();

    // Dynamic programming
    int coinLen = sizeof(coins) / sizeof(coins[0]);
    int change[money + 1];

    // Initialize the DP array
    for (int i = 0; i <= money; i++) {
        change[i] = money + 1; // Use money + 1 as infinity
    }
    change[0] = 0; // Base case: 0 coins needed to make amount 0

    // Fill the DP array
    for (int i = 1; i <= money; i++) {
        for (int j = 0; j < coinLen; j++) {
            if (coins[j] <= i) {
                change[i] = min(change[i], change[i - coins[j]] + 1);
            }
        }
    }

    // If change[money] is still money + 1, it means no solution exists
    if (change[money] > money) {
        printf("No solution exists.\n");
    } else {
        printf("Minimum coins required is %d\n", change[money]);
    }

    return 0;
}
