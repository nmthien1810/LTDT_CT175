#include <stdio.h>
#include "matrandinhdinh.h"

int rank[MAX_VERTICES];

void ranking(Graph* G) {
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
	List S1, S2;
	make_null_list(&S1);
	
	for (int u = 1; u <= G->n; u++) {
		if (d[u] == 0)
			push_back(&S1, u);
	}
	
	int k = 0;
	while (S1.size > 0) {
		make_null_list(&S2);
		for (int i = 1; i <= S1.size; i++) {
			int u = element_at(&S1, i);
			rank[u] = k;
			
			for (int v = 1; v <= G->n; v++) {
				if (G->A[u][v] != 0) {
					d[v]--;
					if (d[v] == 0) 
						push_back(&S2, v);
				}
			}
		}
		copy_list(&S1,&S2);
		k++;
	}
}

int main() {
	Graph G;
	int n, m, u, v;
	FILE* file = fopen("dt.txt", "r");
	fscanf(file, "%d%d", &n, &m);
	init_graph(&G, n);
	for (int e = 1; e <= m; e++) {
		fscanf(file, "%d%d", &u, &v);
		add_edge1(&G, u, v);
	}
	
	ranking(&G);
	for (int i = 1; i <= n; i++) {
		printf("rank[%d] = %d\n", i, rank[i]);
	}
	
	fclose(file);	
}
