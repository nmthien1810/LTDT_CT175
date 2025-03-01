#include <stdio.h>

#define MAX_VERTICES 100

typedef struct {
	int A[MAX_VERTICES][MAX_VERTICES];
	int n;
} Graph;

void init_graph(Graph* G, int n) {
	G->n = n;
	for (int i = 1; i <= G->n; i++) {
		for (int  j = 1; j <= G->n; j++) {
			G->A[i][j] = 0;
		}
	}
}

void add_edges(Graph* G, int x, int y) {
	G->A[x][y] += 1;
	G->A[y][x] += 1;
}

int adjacent(Graph* G, int x, int y) {
	return G->A[x][y] != 0;
}

int degree(Graph* G, int x) {
	int deg;
	for (int e = 1; e <= G->n; e++) {
			deg += G->A[x][e];
	}
	return deg;
}
