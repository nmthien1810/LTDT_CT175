#include <stdio.h>
#include "matrandinhke.h"

int main() {
    Graph G;
    int n, m, u, v;

    FILE* file = fopen("dothi.txt", "r"); 
    fscanf(file, "%d%d", &n, &m); 
    init_graph(&G, n); 
    for (int e = 1; e <= m; e++) { 
        fscanf(file, "%d%d", &u, &v); 
        add_edge(&G, u, v); 
    } 

    for (v = 1; v <= n; v++) {
        printf("Cac dinh ke cua %d la: ", v);
        for (int i = 1; i <= G.adj[v].size; i++) {
            printf("%d ", element_at(&G.adj[v], i));
        }
        printf("\n");
    }
       

    fclose(file);
}