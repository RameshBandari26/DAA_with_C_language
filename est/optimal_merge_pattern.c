#include <stdio.h>
#include <limits.h>

void swap(int arr[], int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

int main() {
    // int arr[] = {21, 10, 9, 15, 25, 6, 7, 9};
    //int arr[] = {25, 15, 5, 10, 12, 9, 7, 6, 4};
    // int arr[] = {4, 3, 6, 2};
    int x;
    printf("Enter size: ");
    scanf("%d",&x);
    printf("Enter array:\n");
    int arr[x];
    for(int i=0;i<x;i++){
        scanf("%d",&arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    int totalCost = 0;
    
    while (n >= 2) {
        int min = INT_MAX;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] < min) {
                min = arr[i];
                idx = i;
            }
        }
        swap(arr, idx, n - 1);
        min = INT_MAX;
        idx = -1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] < min) {
                min = arr[i];
                idx = i;
            }
        }
        swap(arr, idx, n - 2);
        
        int mergedCost = arr[n - 1] + arr[n - 2];
        totalCost += mergedCost;
        arr[n - 2] = mergedCost;
        n--;
    }
    
    printf("%d\n", totalCost);
    return 0;
}





// Enter size: 9
// Enter array:
// 25 15 5 10 12 9 7 6 4
// 276
