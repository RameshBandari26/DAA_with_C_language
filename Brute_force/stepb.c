#include <stdio.h>

int countWays(int n) {
    if (n <= 1)
        return 1;
    else
        return countWays(n-1) + countWays(n-2);
}

int main() {
    int n;
    printf("Enter the number of steps: ");
    scanf("%d", &n);
    
    printf("Number of ways to climb the staircase: %d\n", countWays(n));
    
    return 0;
}
