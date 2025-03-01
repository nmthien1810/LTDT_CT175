#include "duyetdothi.cpp"

int main () {
	Graph G;
	init_graph(&G, 5);
	
	for (int i = 1; i <= 5; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add_edges(&G, x, y);
	}
	
//	depth_first_search(&G);
	breath_first_search(&G);
//	depth_first_search_traversal(&G);
}
