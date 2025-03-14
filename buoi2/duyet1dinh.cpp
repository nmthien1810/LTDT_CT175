#include <stdio.h>
#include "matrandinhdinh.h"


void depth_first_search(Graph* G) {
	Stack S;
	make_null_stack(&S);
	int mark[MAX_VERTICES];
	
	for (int i = 1; i <= G->n; i++) {
		mark[i] = 0;
	}
	
	push(&S, 1); 
	printf("Thu tu duyet:\n");
	int count = 0;
	while (!empty(&S)) {
		int x = top(&S);
		pop(&S);
		if (mark[x] != 0)
			continue;
		printf("%d\n", x);
		mark[x] = 1;
		
		List L = neighbors(&(*G), x);
		for (int i = 1; i <= L.size; i++) {
			int y = element_at(&L, i);
			push(&S, y);
		}		
	}
}

void breadth_first_search(Graph* G) {
	Queue Q;
	make_null_queue(&Q);
	int mark[MAX_VERTICES];
	
	for (int i = 1; i <= G->n; i++) {
		mark[i] = 0;
	}
	
	push(&Q, 1);
	
	printf("Thu tu duyet:\n");
	int count = 0;
	while (!empty(&Q)) {
		int x = top(&Q);
		pop(&Q);
		
		if (mark[x] != 0)
			continue;
		printf("%d\n", x);
		mark[x] = 1;
		
		List L = neighbors(&(*G), x);
		for (int i = 1; i <= L.size; i++) {
			int y = element_at(&L, i);
			push(&Q, y);
		}
	}
}

int markt[MAX_VERTICES];
void traversal(Graph* G, int x) {
	if (markt[x] == 1) 
		return;
	printf("%d\n", x);
	markt[x] = 1;
	
	List L = neighbors(&(*G), x);
	for (int i = 1; i <= L.size; i++) {
		int y = element_at(&L, i);
		traversal(&(*G), y);
	}
}

void depth_first_search_traversal(Graph* G) {
	for (int i = 1; i <= G->n; i++) {
		markt[i] = 0;
	}
	printf("Thu tu duyet: \n");
	traversal(&(*G), 1);
}

int main () {
	Graph G; 
    int n, m, u, v; 
    FILE* file = fopen("dothi.txt", "r"); 
    fscanf(file, "%d%d", &n, &m); 
    init_graph(&G, n); 
    for (int e = 1; e <= m; e++) { 
        fscanf(file, "%d%d", &u, &v); 
        add_edge(&G, u, v); 
    } 

	// int n = 4, m = 5;
	// init_graph(&G, n);
	// for (int i = 1; i <= m; i++) {
	// 	int x, y;
	// 	scanf("%d%d", &x, &y);
	// 	add_edge(&G, x, y);
	// }
	
	depth_first_search(&G);
//	breadth_first_search(&G);
//	depth_first_search_traversal(&G);

	fclose(file);
    return 0; 
}
