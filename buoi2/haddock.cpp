#include <stdio.h>
#include "matrandinhdinh.h"

#define white 0
#define black 1
#define gray 2

int color[MAX_VERTICES];
int cycle;

void dfs(Graph* G, int x) {
    color[x] = gray;

    List L = neighbors(G, x);
    for (int i = 1; i <= L.size; i++) {
        int y = element_at(&L, i);
        if (color[y] == gray) {
            cycle = 1;
            return;
        }
        if (color[y] == white) 
            dfs(G, y);
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
            dfs(&(*G), i);
    }
    return cycle;
}

int main () {
	Graph G; 
    int n, m, u, v; 
    FILE* file = fopen("haddock.txt", "r"); 
    fscanf(file, "%d%d", &n, &m); 
    init_graph(&G, n); 
    for (int e = 1; e <= m; e++) { 
        fscanf(file, "%d%d", &u, &v); 
        add_edge1(&G, u, v); 
    } 

    if (contain_cycle(&G))
        printf("NO");
    else    
        printf("YES");

	fclose(file);
    return 0; 
}