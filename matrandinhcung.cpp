#include <stdio.h>

#define MAX_VERTICS 100
#define MAX_EDGE 100

typedef struct {
    int A[MAX_VERTICS][MAX_EDGE];
    int n, m; // so dinh, cung
} Graph;

void init_graph(Graph* G, int n, int m) {
    G->n = n;
    G->m = m;
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <=m; j++) {
            G->A[i][j] = 0;
        }
    }
}

void add_edge(Graph* G, int e, int x, int y) {
    G->A[x][e] = 1;
    G->A[y][e] = 1;
}



int main() {

    return 0;
}