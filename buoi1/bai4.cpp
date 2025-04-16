#include <stdio.h>
#include "matrandinhdinh.h"

int main() { 
    Graph G; 
    int n = 4; 
    init_graph(&G, n); 
    add_edge1(&G, 1, 2); 
    add_edge1(&G, 1, 3); 
    add_edge1(&G, 1, 3); 
    add_edge1(&G, 3, 4); 
    add_edge1(&G, 1, 1); 

    for (int v = 1; v <= n; v++) 
        printf("deg(%d) = %d\n", v, degree(&G, v)); 

    return 0; 
}