#include <stdio.h>

#define MAX_N 100
#define NO_EDGE 0
#define INFINITY 1000000

typedef struct {
    int n;
    int A[MAX_N][MAX_N];
} Graph;

void init_graph (Graph *G, int n){
    G->n = n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            G->A[i][j] = NO_EDGE;
        }
    }
}

void add_edge(Graph *G, int u, int v, int w){
    G->A[u][v] = w;
}

int is_valid(int i, int j, int n, int m){
    return (0 <= i && i < n && j >= 0 && j < m);
}

int mark[MAX_N], pi[MAX_N], p[MAX_N];

void dijkstra(Graph *G, int u){    
    for(int i = 1; i <= G->n; i++){
        mark[i] = 0;
        pi[i] = INFINITY;
    }

    pi[u] = 0;
    p[u] = -1;

    for (int i = 1; i <= G->n - 1; i++) {
        int min_pi = INFINITY;
        for (int j = 1; j <= G->n; j++){
            if (!mark[j] && pi[j] < min_pi) {
                min_pi = pi[j];
                u = j;
            }
        } 

        mark[u] = 1;

        for(int v = 1; v <= G->n; v++){
            if (G->A[u][v] != NO_EDGE && !mark[v] && pi[u] + G->A[u][v] < pi[v]) {
                pi[v] = pi[u] + G->A[u][v]; 
                p[v] = u;
            }
        }       
    }
}
    
int main(){
    Graph G;
    int maze[MAX_N][MAX_N];
    
    int n, m;
    FILE* file = fopen("mecungso.txt", "r");
    fscanf(file, "%d%d", &n, &m);
    init_graph(&G, n * m);

    int adj[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(file, "%d", &maze[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int u = i * m + j + 1;
            for(int k = 0; k < 4; k++){
                int adjR = i + adj[k][0];
                int adjC = j + adj[k][1];                        
                if(is_valid(adjR, adjC, n, m)){    
                    int v = adjR * m + adjC + 1; 
                    add_edge(&G, u, v, maze[adjR][adjC]);
                }                
            }
        }
    }

    dijkstra(&G, 1);
    
    printf("%d", pi[n * m] + maze[0][0]);
}