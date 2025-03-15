#include <stdio.h>
#include "matrandinhdinh.h"

void depth_first_search(Graph* G, int x, int mark[]) {
    Stack S;
    make_null_stack(&S);

    push(&S, x);
    
    printf("Thu tu duyet: ");
    while (!empty_stack(&S)) {
        int a = top_stack(&S);
        pop(&S);
        
        if (mark[a] != 0)
            continue; 
        printf("%d ", a);
        mark[a] = 1;
        
        List L = neighbors(G, a);
        for (int i = 1; i <= L.size; i++) {
            int y = element_at(&L, i);
            push(&S, y);
        }
    }
}

void breadth_first_search(Graph* G, int x, int mark[]) {
	Queue Q;
	make_null_queue(&Q);
	
	enQueue(&Q, x);
	
	printf("Thu tu duyet:\n");
	while (!empty_queue(&Q)) {
		int a = top_queue(&Q);
		deQueue(&Q);
		
		if (mark[a] != 0)
			continue;
		printf("%d\n", a);
		mark[a] = 1;

		
		List L = neighbors(&(*G), a);
		for (int i = 1; i <= L.size; i++) {
			int y = element_at(&L, i);
			enQueue(&Q, y);
		}
	}
}

void traversal(Graph* G, int x, int mark[]) {
    if (mark[x] == 1) 
		return;
	printf("%d ", x);
	mark[x] = 1;
	
	List L = neighbors(&(*G), x);
	for (int i = 1; i <= L.size; i++) {
		int y = element_at(&L, i);
		traversal(&(*G), y, mark);
	}
}

void connected_components(Graph* G) { 
    int mark[MAX_VERTICES];
    for (int i = 1; i <= G->n; i++) {
		mark[i] = 0;
	}

    for (int i = 1; i <= G->n; i++) {
        if (mark[i] == 0) { 
            depth_first_search(&(*G), i, mark);
            //breadth_first_search(&(*G), i);
            //traversal(&(*G), i);
            printf("\n");
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
