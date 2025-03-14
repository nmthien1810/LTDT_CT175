#include <stdio.h>
#include "C:\\Users\student\Downloads\matrandinhdinh.h"

void topo_sort(Graph* G, List* L) {
	Queue Q;
	make_null_queue(&Q);
	int d[MAX_VERTICES];
	for (int u = 1; u <= G->n; u++) {
		d[u] = 0;
	}  
	for (int x = 1; x <= G->n; x++) {
		for (int u = 1; u <= G->n; u++) {
			if (G->A[x][u] != 0)
				d[u]++;
		}
	}

	
	for (int u = 1; u <= G->n; u++) {
		if (d[u] == 0)
			push(&Q, u);
	}
	
	make_null_list(L);
	
	while (!empty(&Q)) {
		int u = top(&Q);
		pop(&Q);
		push_back(L, u);
			
		for (int v = 1; v <= G->n; v++) {
			if (G->A[u][v] != 0) {
				d[v]--;
				if (d[v] == 0) 
					push(&Q, v);
				
			}
		}
	}
}

int main() {
	Graph G;
	List L;
	int n, m, u, v;
	FILE* file = fopen("C:\\Users\\student\\Downloads\\dt.txt", "r");
	fscanf(file, "%d%d", &n, &m);
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		fscanf(file, "%d%d", &u, &v);
		add_edge1(&G, u, v);
	}
	
	topo_sort(&G, &L);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", element_at(&L, i));
	}
	
	fclose(file);	
}
