#ifndef GRAPH_DC
#define GRAPH_DC

#define MAX_VERTICES 100
#define MAX_EDGES 100

typedef struct {
    int n, m;
    int A[MAX_VERTICES][MAX_EDGES];
} Graph;

void init_graph(Graph* G, int n, int m) {
    G->n = n;
    G->m = m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            G->A[n][m] = 0;
        }
    }
}

void add_edge(Graph* G, int e, int x, int y) {
    G->A[x][e] = 1;
    G->A[y][e] = 1;
}

int adjacent(Graph* G, int x, int y) {
    for (int e = 0; e <= G->m; e++) {
        if (G->A[x][e] == 1 && G->A[y][e] == 1)
            return 1;
    }
    return 0;
}

int degree(Graph* G, int x) {
    int deg = 0;
    for (int e = 1; e <= G->m; e++) {
        if (G->A[x][e] != 0)
            deg++;
    }
    return deg;
}

#endif 