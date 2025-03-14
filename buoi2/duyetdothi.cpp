<<<<<<< HEAD
#include "graph.cpp"
#include "list.cpp"
#include "stack.cpp"
#include "queue.cpp"

void depth_first_search(Graph* G) {
	Stack S;
	make_null_stack(&S);
	int mark[MAX_VERTICES];
	
	for (int i = 1; i <= G->n; i++) {
		mark[i] = 0;
	}
	
	push(&S, 1); 
	printf("Thu tu duyet:\n");
	
	while (!empty(&S)) {
		int x = top(&S);
		pop(&S);
		if (mark[x] != 0)
			continue;
		printf("%d\n", x);
		mark[x] = 1;
		
		List L = neighbors(&(*G), x);
		for (int j = 1; j <= L.size; j++) {
			int y = element_at(&L, j);
			push(&S, y);
		}		
	}
}

void breath_first_search(Graph* G) {
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
		count++;
		
		List L = neighbors(&(*G), x);
=======
#include <stdio.h>
#include "matrandinhdinh.h"

void depth_first_search(Graph* G, int x, int mark[]) {
    Stack S;
    make_null_stack(&S);

    push(&S, x);
    
    printf("Thu tu duyet: ");
    while (!empty(&S)) {
        int a = top(&S);
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
	
	push(&Q, x);
	
	printf("Thu tu duyet:\n");
	while (!empty(&Q)) {
		int a = top(&Q);
		pop(&Q);
		
		if (mark[a] != 0)
			continue;
		printf("%d\n", a);
		mark[a] = 1;

		
		List L = neighbors(&(*G), a);
>>>>>>> 0977523 (.)
		for (int i = 1; i <= L.size; i++) {
			int y = element_at(&L, i);
			push(&Q, y);
		}
	}
<<<<<<< HEAD
	if (count == G->n)
		printf("Do thi lien thong");
	else 
		printf("Do thi khong lien thong");
}

int mark[MAX_VERTICES];

void traversal(Graph* G, int x) {
	if (mark[x] == 1) 
		return;
	printf("Duyet %d\n", x);
=======
}

void traversal(Graph* G, int x, int mark[]) {
    if (mark[x] == 1) 
		return;
	printf("%d ", x);
>>>>>>> 0977523 (.)
	mark[x] = 1;
	
	List L = neighbors(&(*G), x);
	for (int i = 1; i <= L.size; i++) {
		int y = element_at(&L, i);
<<<<<<< HEAD
		traversal(&(*G), y);
	}
}

void depth_first_search_traversal(Graph* G) {
	for (int i = 1; i <= G->n; i++) {
		mark[i] = 0;
	}
	traversal(&(*G), 1);
}
=======
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
>>>>>>> 0977523 (.)
