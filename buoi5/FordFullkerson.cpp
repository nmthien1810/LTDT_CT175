#include <stdio.h>

#define MAX_N 100
#define INFI 1000000
#define NO_EDGE 0

typedef struct {
    int C[MAX_N][MAX_N];
    int F[MAX_N][MAX_N];
    int n;
} Graph;

void init_graph(Graph* G, int n) {
    G->n = n;
    for (int i = 1; i <= G->n; i++) {
        for (int j = 1; j <= G->n; j++) {
            G->C[i][j] = 0;
        }
    }
}

void init_flow(Graph* G) {
    for (int i = 1; i <= G->n; i++) {
        for (int j = 1; j <= G->n; j++) {
            G->F[i][j] = 0;
        }
    }
}

void add_edge(Graph* G, int u, int v, int w) {
    G->C[u][v] = w;
}

typedef struct {
    int dir, pre, sigma;
} Label;

typedef struct {
    int data[MAX_N];
    int front, rear;
} Queue;

void make_null_queue(Queue* Q) {
    Q->front = 0;
    Q->rear = - 1;
}

int empty_queue(Queue* Q) {
    return Q->front > Q->rear;
}

void enqueue(Queue* Q, int val) {
    Q->data[++Q->rear] = val;
}

void dequeue(Queue* Q) {
    Q->front++;
}

int top_queue(Queue* Q) {
    return Q->data[Q->front];
}

Label labels[MAX_N];

int min(int a, int b) {
    return a < b ? a : b;
}

int FordFullkerson(Graph* G, int s, int t) {
    init_flow(G);
    int sum_flow = 0;
    Queue Q;

    do {
        for (int u = 1; u <= G->n; u++) {
            labels[u].dir = 0;
        }

        labels[s].dir = 1;
        labels[s].pre = s; 
        labels[s].sigma = INFI;

        make_null_queue(&Q);
        enqueue(&Q, s);

        int found = 0;
        while (!empty_queue(&Q)) {
            int x = top_queue(&Q);
            dequeue(&Q);
            for (int v = 1; v <= G->n; v++) {
                if (labels[v].dir == 0 && G->C[x][v] != NO_EDGE && G->F[x][v] < G->C[x][v]) {
                    labels[v].dir = 1;
                    labels[v].pre = x;
                    labels[v].sigma = min(labels[x].sigma, G->C[x][v] - G->F[x][v]);
                    enqueue(&Q, v);
                }

                if (labels[v].dir == 0 && G->C[v][x] != NO_EDGE && G->F[v][x] > 0) {
                    labels[v].dir = -1;
                    labels[v].pre = x;
                    labels[v].sigma = min(labels[x].sigma, G->F[x][v]);
                    enqueue(&Q, v);
                }
            }
            if (labels[t].dir != 0) {
                found = 1;
                break;
            }
        }

        if (found) {
            int x = t;
            int sigma = labels[x].sigma;
            sum_flow += sigma;

            while (x != s) {
                int u = labels[x].pre;
                if (labels[x].dir > 0)
                    G->F[u][x] += sigma;
                else    
                    G->F[u][x] -= sigma;
                x = u; 
            } 
        } else  
            break;

    } while (1);

    return sum_flow;
}

int main() {
    Graph G; 
    int n, m, u, v, c; 
    FILE* file = fopen("FordFullkerson.txt", "r");
    fscanf(file, "%d%d", &n, &m); 
    init_graph(&G, n); 
     
    for (int e = 0; e < m; e++) { 
        fscanf(file, "%d%d%d", &u, &v, &c); 
        G.C[u][v] = c; 
    } 

    int max_flow = FordFullkerson(&G, 1, n); 
    printf("Max flow: %d\n", max_flow); 
   
}