#include <stdio.h>

#define MAXN 100
#define NO_EDGE 0
#define INFINITY 999999

int pi[MAXN];
int p[MAXN];
int mark[MAXN];
int cnt[MAXN];

typedef struct {
	int n;
	int A[MAXN][MAXN];
} Graph;

void init_graph(Graph* G, int n) {
	G->n = n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			G->A[i][j] = NO_EDGE;
		}
	}
} 

void Dijkstra(Graph* G, int s) {
	int i, j;
	for (i = 1; i <=G->n; i++) {
		pi[i] = INFINITY;
		mark[i] = 0;
        cnt[i] = 0;
	}	
	
	pi[s] = 0;
	p[s] = -1;
    cnt[s] = 1;
	
	for (int k = 1; k < G->n; k++) {
		int min_pi = INFINITY;
		for (j = 1; j <= G->n; j++) {
			if (mark[j] == 0 && pi[j] < min_pi) {
				min_pi = pi[j];
				i = j;
			}
		}
		
		mark[i] = 1;

		for (j = 1; j <= G->n; j++) {
			if (G->A[i][j] != NO_EDGE && mark[j] == 0) {
				if (pi[j] > pi[i] + G->A[i][j]) {
					pi[j] = pi[i] + G->A[i][j];
					p[j] = i;
                    cnt[j] = cnt[i];
				} else if (pi[j] == pi[i] + G->A[i][j]){
                    cnt[j] += cnt[i];
                }
			}
		}
	}
}

int main() {
	Graph G;
	int n, m, u, v, w;
	FILE* file = fopen("sdd.txt", "r");
	fscanf(file, "%d%d", &n, &m);
	init_graph(&G, n);
	for (int i = 1; i <= m; i++) {
		fscanf(file, "%d%d%d", &u, &v, &w);
		G.A[u][v] = w;
		G.A[v][u] = w;
	}
	
	Dijkstra(&G, 1);

    if (pi[n] == INFINITY) {
        printf("-1 0");
    } else {
        printf("%d %d", pi[n], cnt[n]);
    }
	
}

