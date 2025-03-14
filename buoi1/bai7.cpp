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

    for (v = 1; v <= n; v++) 
        printf("deg(%d) = %d\n", v, degree(&G, v)); 

    fclose(file);
}