#include "stdio.h"

#define MAX_N 100
#define INFINITY 100000
#define NO_EDGE 0

int mark[MAX_N];

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

typedef struct {
    int size;
    int data[MAX_N];
} List;

void make_null(List* L) {
    L->size = 0;
}

void push_back(List* L, int value) {
    L->data[L->size] = value;
    L->size++;
}

int element_at(List* L, int i) {
    return L->data[i - 1];
}

int distance(int u, List* L, Graph* G) {
    int min_dist = INFINITY;
    int min_v = -1;
    for (int i = 1; i <= L->size; i++) {
        int v = element_at(L, i);
        if (G->A[u][v] != NO_EDGE && min_dist > G->A[u][v]) {
            min_dist = G->A[u][v];
            min_v = v;
        }
    }
    return min_v;
}

int Prime(Graph* G, Graph* T) {
    init_graph(T, G->n);
    List L;
    make_null(&L);
    for (int i = 1; i <= G->n; i++) {
        mark[i] = 0;
    }
    push_back(&L, 1);
    mark[1] = 1;
    int sum_w = 0;

    for (int i = 1; i < G->n; i++) {
        int min_dist = INFINITY, min_u, min_v;
        for (int u = 1; u <= G->n; u++) {
            if (mark[u] == 0) {
                int v = distance(u, &L, G);
                if (v != -1 && G->A[u][v] < min_dist) {
                    min_dist = G->A[u][v];
                    min_v = v;
                    min_u = u;
                }
            }
        }
        push_back(&L, min_u);
        mark[min_u] = 1;
        add_edge(T, min_u, min_v, min_dist);
        sum_w += min_dist;
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
