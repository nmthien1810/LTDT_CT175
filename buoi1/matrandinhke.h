#ifndef GRAPH_DK
#define GRAPH_DK

#define MAX_VERTICES 100
#define MAX_ELEMENTS 100

typedef struct {
	int data[MAX_ELEMENTS];
	int size;
} List;

typedef struct {
    int n;
    List adj[MAX_VERTICES];
} Graph;

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

int count_list(List* L) {
	return L->size;
}

void init_graph(Graph* G, int n) {
    G->n = n;
    for (int i = 1; i <= n; i++) {
        make_null_list(&G->adj[i]);
    }
}

void add_edge(Graph* G, int x, int y) {
    push_back(&G->adj[x], y);
    push_back(&G->adj[y], x);
}

int adjacent(Graph* G, int x, int y) {
    for (int i = 1; i < G->adj[x].size; i++) {
        if (element_at(&G->adj[i], i) == y)
			return 1;
    }
	return 0;
}

int degree(Graph* G, int x) {
	return G->adj[x].size;
}

#endif