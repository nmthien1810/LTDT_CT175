#include <stdio.h>

#define MAXN 100
#define INFINITY 1000000

int pi[MAXN];
int p[MAXN];
int visited[MAXN];

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

void find_negative_cycle(Graph* G, int start) {
    int cycle[MAXN], cycle_size = 0;
    int x = start;

    if (visited[x]) 
        return;
    visited[x] = 1; 

    for (int i = 0; i < G->n; i++) {
        x = p[x]; 
    }

    int y = x;
    do {
        cycle[cycle_size++] = y;
        y = p[y];
    } while (y != x);

    cycle[cycle_size++] = x; 

    printf("Chu trình âm: ");
    for (int i = cycle_size - 1; i >= 0; i--) {
        printf("%d ", cycle[i]);
    }
    printf("\n");
}


void BellmanFord(Graph* G, int s) {
    for (int i = 1; i <= G->n ; i++) {
        pi[i] = INFINITY;
        visited[i] = 0;
    }
    pi[s] = 0;
    p[s] = -1;
    for (int i = 1; i < G->n; i++) {
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
        if (pi[u] + w < pi[v]) {
            find_negative_cycle(G, v);
            return;
        }
    }
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
	
}