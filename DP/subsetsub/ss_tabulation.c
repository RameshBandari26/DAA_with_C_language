// Subset Sum with tabulation.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool ss(int n, int s, int wt[]) {

    bool a[n+1][s+1];
    memset(a,-1,sizeof(a));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
    
            if (j == 0){
                a[i][j]=true;
                continue;
            }
            if (i == 0){
                a[i][j]=false;
                continue;
            }
            if (wt[n - 1] <= j) {
                a[i][j]=a[i-1][j-wt[i-1]]||a[n-1][s];
            } 
            else {
                a[i][j]=a[n-1][s];
            }
        }
    }
    return a[n][s];
}

int main() {
    printf("Enter number of weights: ");
    int n, s;
    scanf("%d", &n);
    printf("Enter weights: ");
    int wt[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
    printf("Enter sum: ");
    scanf("%d", &s);
    if (ss(n, s, wt)) {
        printf("Found a subset with given sum");
    } else {
        printf("No subset with sum %d exists.\n", s);
    }
    return 0;
}
