#include <stdio.h>
#include "matrandinhdinh.h"

#define INFINITY 1000000

int d[MAX_VERTICES];

void topo_sort(Graph* G, List* L) {
    Queue Q;
    make_null_queue(&Q);

    int deg[MAX_VERTICES];

    for (int u = 1; u <= G->n; u++) {
        deg[u] = 0;
    }
    for (int x = 1; x <= G->n; x++) {
        for (int u = 1; u <= G->n; u++) {
            if (G->A[x][u] > 0)
                deg[u]++;
        }
    }

    for (int u = 1; u <= G->n; u++) {
        if (deg[u] == 0)
            push(&Q, u);
    }

    make_null_list(L);

    while (!empty(&Q)) {
        int u = top(&Q);
        pop(&Q);
        push_back(L, u);

        for (int v = 1; v <= G->n; v++) {
            if (G->A[u][v] != 0) {
                deg[v]--;
                if (deg[v] == 0)
                    push(&Q, v);
            }
        } 
    }
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
	Graph G;
	List L;
	int n, u, x, v, a, b;
	FILE* file = fopen("pro.txt", "r");
	fscanf(file, "%d", &n);
	init_graph(&G, n + 2);
	d[n + 1] = 0;
	
	for (u = 1; u <= n; u++) {
		fscanf(file, "%d", &d[u]);
		do {
			fscanf(file, "%d", &x);
			if (x > 0)
				add_edge1(&G, x, u);
		} while (x > 0);
	}

    fscanf(file, "%d%d", &a, &b);

    fclose(file);

    for (u = 1; u <= n; u++) {
        int deg_neg = 0;
        for (x = 1; x <= n; x++) {
            if (G.A[x][u] > 0)
                deg_neg++;
        }
        if (deg_neg == 0)
            add_edge1(&G, n + 1, u);
    }

    for (u = 1; u <= n; u++) {
        int deg_pos = 0;
        for (v = 1; v <= n; v++) {
            if (G.A[u][v] > 0)
                deg_pos++;
        }
        if (deg_pos == 0)
            add_edge1(&G, u, n + 2);
    }

    topo_sort(&G, &L);

    int t[MAX_VERTICES];
    t[n + 1] = 0;
    for (int i = 2; i <= L.size; i++) {
        u = element_at(&L, i);
        t[u] = -1;
        for (x = 1; x <= G.n; x++) {
            if (G.A[x][u] > 0)
                t[u] = max(t[u], t[x] + d[x]);
        }
    }

    int T[MAX_VERTICES];
    T[n + 2] = t[n + 2];
    for (int i = L.size - 1; i >= 1; i--) {
        u = element_at(&L, i);
        T[u] = INFINITY;
        for (v = 1; v <= G.n; v++) {
            if (G.A[u][v] > 0)
                T[u] = min(T[u], T[v] - d[u]);
        }
    }

    if (b > t[a] && b < T[a])
        printf("YES");
    else    
        printf("NO");

}