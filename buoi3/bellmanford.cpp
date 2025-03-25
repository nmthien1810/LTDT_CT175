#include <stdio.h>

#define MAXN 100
#define INFINITY 1000000

int pi[MAXN];
int p[MAXN];
int path[MAXN];

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    int n, m;
    Edge edges[1000];
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

void BellmanFord(Graph* G, int s) {
    for (int i = 1; i <= G->n ; i++) {
        pi[i] = INFINITY;
    }
    pi[s] = 0;
    p[s] = -1;
    for (int j = 1; j < G->n; j++) {
        for (int k = 0; k < G->m; k++) {
            int u = G->edges[k].u;
            int v = G->edges[k].v;
            int w = G->edges[k].w;
            if (pi[u] + w < pi[v]){
                pi[v] = pi[u] + w;
                p[v] = u;
            }
        }
    }
    for (int k = 0; k < G->m; k++) {
        int u = G->edges[k].u;
        int v = G->edges[k].v;
        int w = G->edges[k].w;
        if (pi[u] + w < pi[v]){
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
	Graph G;
	int n, m, u, v, w;
	FILE* file = fopen("bellmanford2.txt", "r");
	fscanf(file, "%d%d", &n, &m);
	init_graph(&G, n);
	for (int i = 0; i < m; i++) {
		fscanf(file, "%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	
	BellmanFord(&G, 1);
	
	for (int i = 1; i <= n; i++) {
		printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);	
	}

}