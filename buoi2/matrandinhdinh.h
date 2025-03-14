#ifndef GRAPH_DD
#define GRAPH_DD

#define MAX_VERTICES 100
#define MAX_ELEMENTS 100

typedef struct {
	int A[MAX_VERTICES][MAX_VERTICES];
	int n;
} Graph;

void init_graph(Graph* G, int n) {
	G->n = n;
	for (int i = 1; i <= n; i++) {
		for (int  j = 1; j <= n; j++) {
			G->A[i][j] = 0;
		}
	}
}

void add_edge(Graph* G, int x, int y) {
	G->A[x][y] += 1;
	G->A[y][x] += 1;
} 

void add_edge1(Graph* G, int x, int y) {
	G->A[x][y] += 1;
} 

int adjacent(Graph* G, int x, int y) {
	return G->A[x][y] != 0;
}

int degree(Graph* G, int x) {
	int deg = 0;
	for (int e = 1; e <= G->n; e++) {
		deg += G->A[x][e];
	}
	return deg;
}

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

int count_list(List* L) {
	return L->size;
}

List neighbors(Graph* G, int x) {
	List L;
	make_null_list(&L);
	for (int y = 1; y <= G->n; y++) {
		if (G->A[x][y] > 0)
		push_back(&L, y);
	}
	return L;
}

typedef struct {
	int data[MAX_ELEMENTS];
	int size;	
} Stack;

void make_null_stack(Stack* S) {
	S->size = 0;
}

void push(Stack* S, int x) {
	S->data[S->size] = x;
	S->size++;
}

int top(Stack* S) {
	return S->data[S->size - 1];
}

void pop(Stack* S) {
	S->size--;
}

int empty(Stack* S) {
	return S->size == 0;
}

typedef struct {
	int data[MAX_ELEMENTS];
	int front, rear;
} Queue;

void make_null_queue(Queue* Q) {
	Q->front = 0;
	Q->rear = -1;
}

void push(Queue* Q, int x) {
	Q->rear++;
	Q->data[Q->rear] = x;		
}

int top(Queue* Q) {
	return Q->data[Q->front];
}

void pop(Queue* Q) {
	Q->front++;
}

int empty(Queue* Q) {
	return Q->front > Q->rear;
}

#endif