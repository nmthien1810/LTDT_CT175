#include <stdio.h>
#include "matrandinhdinh.h"

int color[MAX_VERTICES];
int fail;

void colorize(Graph* G, int x, int c) {
    if (color[x] == -1) {
        color[x] = c;

        List L = neighbors(&(*G), x);
        for (int i = 1; i <= L.size; i++) {
            int y = element_at(&L, i);
            colorize(&(*G), y, !c);
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
            colorize(&(*G), i, 0);            
    }
    return !fail;
}

int main () {
	Graph G; 
    int n, m, u, v; 
    FILE* file = fopen("db.txt", "r"); 
    fscanf(file, "%d%d", &n, &m); 
    init_graph(&G, n); 
    for (int e = 1; e <= m; e++) { 
        fscanf(file, "%d%d", &u, &v); 
        add_edge(&G, u, v); 
    } 
	
    if (is_bigraph(&G))
        printf("YES");
    else    
        printf("NO");


	fclose(file);
    return 0; 
}
