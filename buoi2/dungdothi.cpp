#include <stdio.h>
#include "matrandinhdinh.h"

int mark[MAX_VERTICES], parent[MAX_VERTICES];

void breadth_first_search(Graph* G, int x) {
	Queue Q;
	make_null_queue(&Q);
	
	enQueue(&Q, x);
	
	while (!empty_queue(&Q)) {
		int a = top_queue(&Q);
		deQueue(&Q);
		
		if (mark[a] != 0)
			continue;

		mark[a] = 1;
		
		List L = neighbors(&(*G), a);
		for (int i = 1; i <= L.size; i++) {
			int y = element_at(&L, i);
			enQueue(&Q, y);
		}
	}
}

void connected_components(Graph* G) { 
    for (int i = 1; i <= G->n; i++) {
		mark[i] = 0;
        parent[i] = 0;
	}

    for (int i = 1; i <= G->n; i++) {
        if (mark[i] == 0) { 
            breadth_first_search(G, i);
        } 
    }      
}

int main () {
	Graph G; 
    int n, m, u, v; 
    FILE* file = fopen("dothi1.txt", "r"); 
    fscanf(file, "%d%d", &n, &m); 
    init_graph(&G, n); 
    for (int e = 1; e <= m; e++) { 
        fscanf(file, "%d%d", &u, &v); 
        add_edge(&G, u, v); 
    } 

    connected_components(&G);

	fclose(file);
    return 0; 
}
