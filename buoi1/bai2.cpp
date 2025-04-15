#include <stdio.h>
#include "matrandinhcung.h"

int main() {
    Graph G;
    int n = 7, m = 9;
    init_graph(&G, n, m);

    add_edge(&G, 1, 1, 2); 
    add_edge(&G, 2, 1, 3); 
    add_edge(&G, 3, 1, 3); 
    add_edge(&G, 4, 3, 6); 
    add_edge(&G, 5, 1, 4); 
    add_edge(&G, 6, 3, 4);    
    add_edge(&G, 7, 6, 5);    
    add_edge(&G, 8, 6, 5);    
    add_edge(&G, 9, 5, 4);    
    
    for (int v = 1; v <= n; v++) {
        printf("deg(%d) = %d\n", v, degree(&G, v));
    }
}
