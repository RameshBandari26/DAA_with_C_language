#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int shortestCommonSupersequence(char *X, char *Y) {
    int m = strlen(X), n = strlen(Y);
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    printf("Length of Shortest Common Supersequence is %d\n", shortestCommonSupersequence(X, Y));
    return 0;
}