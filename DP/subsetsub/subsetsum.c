// Subset Sum

#include <stdio.h>
#include <stdbool.h>

bool ss(int n, int s, int wt[]) {
    if (s == 0)
        return true;
    if (n == 0)
        return false;
    if (wt[n - 1] <= s) {
        return ss(n - 1, s-wt[n-1], wt)||ss(n-1,s,wt);
    } else {
        return ss(n - 1, s, wt);
    }
}

int main() {
    printf("Enter number of weights: ");
    int n, s;
    scanf("%d", &n);
    printf("Enter sum: ");
    scanf("%d", &s);
    printf("Enter weights: ");
    int wt[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
    if (ss(n, s, wt)==true) {
        printf("Found a subset with given sum");
    } else {
        printf("No subset with sum %d exists.\n", s);
    }
    return 0;
}
