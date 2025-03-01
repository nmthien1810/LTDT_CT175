#include "graph.cpp"

#define MAX_ELEMENTS 100

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
	for (int e = 1; e <= G->n; e++) {
		if (G->A[x][e] > 0)
			push_back(&L, e);
	}
	return L;
}
