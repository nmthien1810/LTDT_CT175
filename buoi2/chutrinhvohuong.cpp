#include <stdio.h>
#include "matrandinhdinh.h"

#define white 0
#define black 1
#define gray 2

int color[MAX_VERTICES];
int cycle;

void dfs(Graph* G, int x, int parent) {
    color[x] = gray;

    List L = neighbors(G, x);
    for (int i = 1; i <= L.size; i++) {
        int y = element_at(&L, i);
        if (y == parent)
            continue;
        if (color[y] == gray) {
            cycle = 1;
            return;
        }
        if (color[y] == white) 
            dfs(G, y, x);
    }
    color[x] = black;
}

int contain_cycle(Graph* G) {
    for (int i = 1; i <= G->n; i++) {
        color[i] = white;
    }

    cycle = 0;
    for (int i = 1; i <= G->n; i++) {
        if (color[i] == white)
            dfs(&(*G), i, 0);
    }
    return cycle;
}

int main () {
	Graph G; 
    int n, m, u, v; 
    FILE* file = fopen("db1.txt", "r"); 
    fscanf(file, "%d%d", &n, &m); 
    init_graph(&G, n); 
    for (int e = 1; e <= m; e++) { 
        fscanf(file, "%d%d", &u, &v); 
        add_edge(&G, u, v); 
    } 

    if (contain_cycle(&G))
        printf("YES");
    else    
        printf("NO");

	fclose(file);
    return 0; 
}