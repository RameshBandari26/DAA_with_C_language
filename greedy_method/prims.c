#include <stdio.h>
#include <stdlib.h>

int i, j, a, b, u, v, n, ne = 1;
int visited[10] = {0}, mincost = 0, min, cost[25][25];

int main() 
{
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[1] = 1;
    printf("\n");
    while (ne < n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            if (visited[i] != 0) {
                for (j = 1; j <= n; j++) {
                    if (cost[i][j] < min && visited[j] == 0) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0) {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\n\tMinimum Cost = %d\n", mincost);
    return 0;
}

/*Enter the number of vertices: 5

Enter the cost adjacency matrix:
0 8 5 0 0
8 0 9 11 0
5 9 0 15 10
0 11 15 0 7
0 0 10 7 0

1 edge (1,3) = 5
2 edge (1,2) = 8
3 edge (3,5) = 10
4 edge (5,4) = 7

        Minimum Cost = 30
*/