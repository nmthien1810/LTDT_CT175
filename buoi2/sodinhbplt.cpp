#include <stdio.h>
#include "matrandinhdinh.h"

void depth_first_search(Graph* G, int x, int mark[], int* count_vertex) {
    Stack S;
    make_null_stack(&S);

    push(&S, x);
    
    while (!empty(&S)) {
        int a = top(&S);
        pop(&S);
        
        if (mark[a] != 0)
            continue;           
        mark[a] = 1;
        (*count_vertex)++;
        
        List L = neighbors(G, a);
        for (int i = 1; i <= L.size; i++) {
            int y = element_at(&L, i);
            push(&S, y);
        }
    }
}

void breadth_first_search(Graph* G, int x, int mark[], int* count_vertex) {
	Queue Q;
	make_null_queue(&Q);
	
	push(&Q, x);
	
	while (!empty(&Q)) {
		int a = top(&Q);
		pop(&Q);
		
		if (mark[a] != 0)
			continue;
		mark[a] = 1;
        (*count_vertex)++;
		
		List L = neighbors(&(*G), a);
		for (int i = 1; i <= L.size; i++) {
			int y = element_at(&L, i);
			push(&Q, y);
		}
	}
}

void traversal(Graph* G, int x, int mark[], int* count_vertex) {
    if (mark[x] == 1) 
		return;
	mark[x] = 1;
    (*count_vertex)++;
	
	List L = neighbors(&(*G), x);
	for (int i = 1; i <= L.size; i++) {
		int y = element_at(&L, i);
		traversal(&(*G), y, mark, &(*count_vertex));
	}
}

void vertices_of_component(Graph* G) { 
    int mark[MAX_VERTICES];
    for (int i = 1; i <= G->n; i++) {
		mark[i] = 0;
	} 

    int count = 0;
    for (int i = 1; i <= G->n; i++) {
        if (mark[i] == 0) { 
            int count_vertex = 0;   
            depth_first_search(&(*G), i, mark, &count_vertex);
            // breadth_first_search(&(*G), i, mark, &count_vertex);
            // traversal(&(*G), i, mark, &count_vertex);
            printf("So dinh bplt thu %d: %d\n", ++count, count_vertex);
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

	vertices_of_component(&G);

	fclose(file);
    return 0; 
}