#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_ELEMENTS 100

typedef struct {
	int A[MAX_ELEMENTS][MAX_ELEMENTS];
	int n;
} Graph;

void init_graph(Graph* G, int n) {
	G->n = n;
	for (int i = 1; i <= n; i++) {
		for (int  j = 1; j <= n; j++) {
			G->A[i][j] = 0;
		}
	}
}

void add_edge(Graph* G, int x, int y) {
	G->A[x][y] += 1;
	G->A[y][x] += 1;
}

typedef struct {
	int data[MAX_ELEMENTS];
	int size;
} List;

void make_null_list(List* L) {
	L->size = 0;
}

void push_back(List* L, int x) {
	L->data[L->size] = x;
	L->size++;
}

int element_at(List* L, int i) {
	return L->data[i - 1];
}

List neighbors(Graph* G, int x) {
	List L;
	make_null_list(&L);
	for (int y = 1; y <= G->n; y++) {
		if (G->A[x][y] > 0)
			push_back(&L, y);
	}
	return L;
}

int color[MAX_VERTICES];
int fail;

void colorize(Graph* G, int x, int c) {
    if (color[x] == -1) {
        color[x] = c;
        
        List L = neighbors(G, x);
        for (int i = 1; i <= L.size; i++) {
            int y = element_at(&L, i);
            colorize(G, y, !c);
        }
    } else if (color[x] != c)
        fail = 1;
}

int is_bigraph(Graph* G) {
    for (int i = 1; i <= G->n; i++) {
        color[i] = -1;
    }
    fail = 0;
    for (int i = 1; i <= G->n; i++) {
        if (color[i] == -1)
            colorize(G, i, 0);
    }
    return !fail;
}

int main () {
	Graph G; 
    int n, m, u, v; 
    scanf("%d%d", &n, &m); 
    init_graph(&G, n); 
    for (int e = 1; e <= m; e++) { 
        scanf("%d%d", &u, &v); 
        add_edge(&G, u, v); 
    } 
    
	
    if (is_bigraph(&G)) {
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0)
                printf("%d ", i);
        }
        printf("\n");
        for (int i = 1; i <= n; i++) {
            if (color[i])
                printf("%d ", i);
        }
    } else    
        printf("IMPOSSIBLE");

}