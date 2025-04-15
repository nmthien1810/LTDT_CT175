#include "stdio.h"

#define MAX_N 100
#define INFINITY 100000
#define NO_EDGE 0

int pi[MAX_N], p[MAX_N], mark[MAX_N];

typedef struct {
    int A[MAX_N][MAX_N];
    int n;
} Graph;

void init_graph(Graph* G, int n) {
    G->n = n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            G->A[i][j] = 0;
        }
    }
}

void add_edge(Graph* G, int u, int v, int w) {
    G->A[u][v] = w;
    G->A[v][u] = w;
}

int Prime(Graph* G, Graph* T) {
    init_graph(T, G->n);
    for (int u = 1; u <= G->n; u++) {
        if (G->A[1][u] != NO_EDGE) {
            pi[u] = G->A[1][u];
            p[u] = 1;
        } else
            pi[u] = INFINITY;
        mark[u] = 0;
    }

    pi[1] = 0;
    p[1] = -1;
    mark[1] = 1;

    int sum_w = 0;
    for (int i = 1; i < G->n; i++) {
        int min_dist = INFINITY, min_u;
        for (int u = 1; u <= G->n; u++) {
            if (mark[u] == 0 && pi[u] < min_dist) {
                min_dist = pi[u];
                min_u = u;
            }
        }

        mark[min_u] = 1;

        add_edge(T, p[min_u], min_u, min_dist);
        sum_w += min_dist;

        for (int v = 1; v <= G->n; v++) {
            if (G->A[min_u][v] != NO_EDGE && mark[v] == 0) {
                if (pi[v] > G->A[min_u][v]) {
                    pi[v] = G->A[min_u][v];
                    p[v] = min_u;
                }
            }
        }
    }
    return sum_w;
}

int main() {
    Graph G, T;
    int n, m, u, v, w;
    FILE* file = fopen("prime.txt", "r");
    fscanf(file, "%d%d", &n, &m);
    init_graph(&G, n);
    for (int e = 1; e <= m; e++) {
        fscanf(file, "%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }

    int sum = Prime(&G, &T);
    printf("%d\n", sum);

    for (int i = 1; i <= T.n; i++) {
        for (int j = 1; j <= T.n; j++) {
            if (T.A[i][j] != NO_EDGE && i < j)
                printf("%d %d %d\n", i, j, T.A[i][j]);
        }
        
    }
}