#include<stdio.h>

#define MAX 10

int path[MAX];
int graph[MAX][MAX];
int V;

void printSolution() {
    printf("Hamiltonian Cycle: ");
    for(int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);
}

int isSafe(int v, int pos) {
    if(graph[path[pos - 1]][v] == 0)
        return 0;
    for(int i = 0; i < pos; i++)
        if(path[i] == v)
            return 0;
    return 1;
}

int hamCycleUtil(int pos) {
    if(pos == V) {
        if(graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }
    for(int v = 1; v < V; v++) {
        if(isSafe(v, pos)) {
            path[pos] = v;
            if(hamCycleUtil(pos + 1) == 1)
                return 1;
            path[pos] = -1;
        }
    }
    return 0;
}

int hamCycle(int src) {
    for(int i = 0; i < V; i++)
        path[i] = -1;
    path[0] = src;
    if(hamCycleUtil(1) == 0) {
        printf("Hamiltonian Cycle does not exist\n");
        return 0;
    }
    printSolution();
    return 1;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    int starting_vertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &starting_vertex);

    hamCycle(starting_vertex);
    
    return 0;
}
