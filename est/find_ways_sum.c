#include <stdio.h>
#include <string.h>

int findWays(int n, int m, int X) {
    int dp[n+1][X+1];
    memset(dp, 0, sizeof(dp));

    for (int j = 1; j <= m && j <= X; j++)
        dp[1][j] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= X; j++) {
            for (int k = 1; k <= m && k < j; k++) {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }

    return dp[n][X];
}

int main() {
    int n = 2, m = 2, X = 3;
    printf("Number of ways: %d\n", findWays(n, m, X));
    return 0;
}