#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "graph.h"

int* create_in_degrees(int a) {
	int* in_degrees = malloc(sizeof(int) * a);
	for (int i = 0; i < a; i++) {
		in_degrees[i] = 0;
		return in_degrees;
	}
}

int main() {
	Graph G = read_graph();
	//initialise array and set all to 0
	int* in_degrees = create_in_degrees(&G.V);

	/*loop through all of the edges in the graph and increment
	*the in - degree for the to - vertex of each edge
	*/
	for (int i = 0; i < G.V; i++) {
		EdgeNodePtr node = G.edges[i].head;
		while (node != NULL) {
			in_degrees[node->edge.to_vertex]++;
			node = node->next;
		}
	}

	//print
	for (int count = 0; count < G.V; count++) {
		printf(" %d in-degree of vertex %d\n", in_degrees[count], count);
	}

	//calculating page rank 
	double pagerank[G.V];
	double vertex_sum[G.V];

	//freeing memory
	free(in_degrees);

	destroy_graph(G);



	return 0;
}