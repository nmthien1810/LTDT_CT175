#include <stdio.h>
#include "matrandinhdinh.h"

Stack S;
int num[MAX_VERTICES];
int min_num[MAX_VERTICES];
int on_stack[MAX_VERTICES];
int k;

int min(int a, int b) {
    return a < b ? a : b;
}

void strong_connect(Graph* G, int x) {
    num[x] = min_num[x] = k;
    k++;
    push(&S, x);
    on_stack[x] = 1;

    List L = neighbors(G, x);
    for (int i = 1; i <= L.size; i++) {
        int y = element_at(&L, i);
        if (num[y] == -1) {
            strong_connect(G, y);
            min_num[x] = min(min_num[x], min_num[y]);
        } else if (on_stack[y]) {
            min_num[x] = min(min_num[x], num[y]);
        }
    }
    printf("num[%d] = %d, min_num[%d] = %d\n", x, num[x], x, min_num[x]); 
    
    if (num[x] == min_num[x]) { 
        printf("Tim thay bo phan lien thong manh\n\n"); 
        int w; 
        do { 
            if (!empty_stack(&S)) {
                w = top_stack(&S); 
                pop(&S); 
                on_stack[w] = 0;
            }                      
        } while (w != x); 
    } 
}

void strong_connect_components(Graph* G) {
    for (int i = 1; i <= G->n; i++) {
        num[i] = -1;
        on_stack[i] = 0;
    }
    k = 1;
    make_null_stack(&S);
    for (int i = 1; i <= G->n; i++) {
        if (num[i] == -1) 
            strong_connect(G, i);
    }
}

int main() {
    Graph G;
    int n, m, u, v;
    FILE* file = fopen("bpltm.txt", "r");
    fscanf(file, "%d%d", &n, &m);
    init_graph(&G, n);
    for (int i = 1; i <= m; i++) {
        fscanf(file, "%d%d", &u, &v);
        add_edge1(&G, u, v);
    }

    strong_connect_components(&G);

    fclose(file);
    return 0;
}