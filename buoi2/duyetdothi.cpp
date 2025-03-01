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
		for (int i = 1; i <= L.size; i++) {
			int y = element_at(&L, i);
			push(&Q, y);
		}
	}
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
	mark[x] = 1;
	
	List L = neighbors(&(*G), x);
	for (int i = 1; i <= L.size; i++) {
		int y = element_at(&L, i);
		traversal(&(*G), y);
	}
}

void depth_first_search_traversal(Graph* G) {
	for (int i = 1; i <= G->n; i++) {
		mark[i] = 0;
	}
	traversal(&(*G), 1);
}
