<<<<<<< HEAD
#include "matrandinhcung.cpp"

int main() {
    Graph G;
    init_graph(&G, 4, 5);
    
}
=======
#include <stdio.h>
#include "matrandinhcung.h"

int main() { 
    Graph G; 
    int n, m, u, v; 
    FILE* file = fopen("dothi.txt", "r"); 
    fscanf(file, "%d%d", &n, &m); 
    init_graph(&G, n, m); 
    for (int e = 1; e <= m; e++) { 
        fscanf(file, "%d%d", &u, &v); 
        add_edge(&G, e, u, v); 
    } 

    for (v = 1; v <= n; v++) 
        printf("deg(%d) = %d\n", v, degree(&G, v)); 

    fclose(file);
    return 0; 
}
>>>>>>> 0977523 (.)
