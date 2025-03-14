#include <stdio.h>
#include "matrandinhdinh.h"

int main() {
    Graph G;
    int n, m, u, v;

    FILE* file = fopen("dothi.txt", "r");
    fscanf(file, "%d%d", &n, &m);
    init_graph(&G, n);
    for (int i = 1; i <= m; i++) {
        fscanf(file, "%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    for (v = 1; v <= n; v++) {
        List L = neighbors(&G, v);
        printf("Cac dinh ke cua %d la: ", v);
        for (int j = 1; j <= L.size; j++) {
            printf("%d ", element_at(&L, j));
        }
        printf("\n");
    }

}