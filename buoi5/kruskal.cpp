#include "stdio.h"

#define MAX_N 100

int parent[MAX_N];

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    Edge edges[MAX_N];
    int n, m;
} Graph;

void init_graph(Graph* G, int n) {
    G->n = n;
    G->m = 0;
}

void add_edge(Graph* G, int u, int v, int w) {
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->edges[G->m].w = w;
    G->m++;
}

int findRoot(int u) { 
    if (parent[u] == u) 
        return u; 
    return findRoot(parent[u]); 
}

void sort(Graph* G) {
    for (int i = 0; i < G->m - 1; i++) {
        for (int j = i + 1; j < G->m; j++) {
            if (G->edges[j].w < G->edges[i].w) {
                Edge tmp = G->edges[j];
                G->edges[j] = G->edges[i];
                G->edges[i] = tmp;
            }        
        }
    }
}

int Kruskal(Graph* G, Graph* T) {
    init_graph(T, G->n);

    for (int u = 0; u < G->n; u++) {
        parent[u] = u;
    }

    int sum_w = 0;
    sort(G);

    for (int i = 0; i < G->m; i++) {
        int u = G->edges[i].u;
        int v = G->edges[i].v;
        int w = G->edges[i].w;
        int root_u = findRoot(u);
        int root_v = findRoot(v);
        if (root_u != root_v) {
            add_edge(T, u, v, w);
            parent[root_v] = root_u;
            sum_w += w;
        }
    }
    return sum_w;
}

int main() {
    Graph G, T;
    int n, m, u, v, w;
    FILE* file = fopen("kruskal.txt", "r");
    fscanf(file, "%d%d", &n, &m);
    init_graph(&G, n);
    for (int e = 1; e <= m; e++) {
        fscanf(file, "%d%d%d", &u, &v, &w);
        if (u < v)
            add_edge(&G, u, v, w);
        else    
            add_edge(&G, v, u, w);
    }

    int sum = Kruskal(&G, &T);
    printf("%d\n", sum);

    for (int e = 0; e < T.m; e++) {
        printf("(%d, %d) = %d\n", T.edges[e].u, T.edges[e].v, T.edges[e].w);
    }
}
