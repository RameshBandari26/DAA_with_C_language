#include <stdio.h>
#include <limits.h>

int mcm(int n, int a[]) {
    int dp[n][n];
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    int n;

    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int a[n + 1];
    printf("Enter the sizes of matrices: ");
    for (int i = 0; i < n + 1; i++) {
        scanf("%d", &a[i]);
    }

    int result = mcm(n + 1, a);
    printf("Minimum number of multiplications is %d\n", result);

    return 0;
}






/*
Enter the number of matrices: 3
Enter the sizes of matrices: 10 20 30 40

Minimum number of multiplications is 18000
*/