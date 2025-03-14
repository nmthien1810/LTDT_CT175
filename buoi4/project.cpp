#include <stdio.h>
#include "C:\\Users\student\Downloads\matrandinhdinh.h"

int d[MAX_VERTICES];

void topo_sort(Graph* G, List* L) {
	Queue Q;
	make_null_queue(&Q);
	int d1[MAX_VERTICES];
	for (int u = 1; u <= G->n; u++) {
		d1[u] = 0;
	}  
	for (int x = 1; x <= G->n; x++) {
		for (int u = 1; u <= G->n; u++) {
			if (G->A[x][u] != 0)
				d1[u]++;
		}
	}

	
	for (int u = 1; u <= G->n; u++) {
		if (d1[u] == 0)
			push(&Q, u);
	}
	
	make_null_list(L);
	
	while (!empty(&Q)) {
		int u = top(&Q);
		pop(&Q);
		push_back(L, u);
			
		for (int v = 1; v <= G->n; v++) {
			if (G->A[u][v] != 0) {
				d1[v]--;
				if (d1[v] == 0) 
					push(&Q, v);
				
			}
		}
	}
}

int main() {
	Graph G;
	List L;
	int n, u, x;
	FILE* file = fopen("C:\\Users\\student\\Downloads\\dt1.txt", "r");
	fscanf(file, "%d", &n);
	init_graph(&G, n + 2);
	d[n + 1] = 0;
	
	for (u = 1; u <= n; u++) {
		fscanf(file, "%d", &d[u]);
		do {
			fscanf(file, "%d", &x);
			if (x > 0)
				add_edge1(&G, x, u);
		} while (x > 0);
	}
	
	for (u = 1; u <= n; u++) {
		int deg_neg = 0;
		for (x = 1; x <= n; x++)
			if (G.A[x][u] > 0)
				deg_neg++;
		if (deg_neg == 0)
			add_edge1(&G, n+1, u); 
	}
	
	for (u = 1; u <= n; u++) {
		int deg_pos = 0;
		for (x = 1; x <= n; x++)
			if (G.A[x][u] > 0)
				deg_pos++;
		if (deg_pos == 0)
			add_edge1(&G, n+1, u); 
	}
	
	topo_sort(&G, &L);
	
	
	
	fclose(file);	
}
