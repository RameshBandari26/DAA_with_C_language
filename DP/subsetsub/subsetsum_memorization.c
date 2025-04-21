// Subset Sum with memorization.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool ss(int n, int s, int wt[]) {

    int a[n+1][s+1];
	memset(a,-1,sizeof(a));
    if(a[n][s]!=-1){
        return a[n][s];
    }
    if (s == 0)
        return true;
    if (n == 0)
        return false;
    if (wt[n - 1] <= s) {
        return a[n][s]=ss(n - 1, s-wt[n-1],wt)||ss(n-1,s,wt);
    } else {
        return a[n][s]=ss(n - 1, s, wt);
    }
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
