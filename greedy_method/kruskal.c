#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <limits.h>
int i,j,u,v,n,ne=1,a,b;
int min,mincost=0,adj[25][25],parent[25];
int find(int i){
    while(parent[i]){
        i=parent[i];
    }
    return i;
}
int uni(int i,int j){
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    return 0;
}
int main(){
    printf("\n Enter the no. of Vertices: ");
    scanf("%d",&n);
    printf("Enter the cost of Adjecent matrix:\n");
    for ( i = 1; i <=n; i++)
    {
        for ( j = 1; j <=n; j++)
        {
            scanf("%d",&adj[i][j]);
            if(adj[i][j]==0)
                adj[i][j]=INT_MAX;
        }    
    } 
    printf("The edges of minimum cost spanning Tree are\n")  ;
    while (ne<n)
    {
        min=INT_MAX;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(adj[i][j]<min){
                    min=adj[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v)){
            printf("%d edge (%d,%d)=%d\n",ne++,a,b,min);
            mincost +=min;
        }
        adj[a][b]=adj[b][a]=INT_MAX;
    }
    printf("\n\t Minimum cost =%d\n",mincost);
    return 0;   
}




/*
Enter the no. of Vertices: 5
Enter the cost of Adjecent matrix:
0 8 5 0 0
8 0 9 11 0
5 9 0 15 10
0 11 15 0 7
0 0 10 7 0
The edges of minimum cost spanning Tree are
1 edge (1,3)=5
2 edge (4,5)=7
3 edge (1,2)=8
4 edge (3,5)=10

         Minimum cost =30
*/