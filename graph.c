#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "graph.h"
/*
* This file is for future usage
*/
Graph create_graph(int v) {

	Graph graph;
	graph.V = v;

	graph.edges = malloc(sizeof(graph.edges) * graph.V);


	for (int count = 0; count < graph.V; count = count + 1) {
		graph.edges[count].head = NULL;
	}
	return graph;
}
void add_edge(Graph graph, int from, int to)
{
	EdgeNodePtr edge_node = malloc(sizeof * edge_node);
	edge_node->edge.to_vertex = to;
	edge_node->next = graph.edges[from].head;
	graph.edges[from].head = edge_node;
}
void destroy_graph(Graph G) {
	for (int i = 0; i < G.V; i++) {
		EdgeNodePtr edge_node = G.edges[i].head;
		while (edge_node != NULL) {
			EdgeNodePtr temp = edge_node;
			edge_node = edge_node->next;
			free(temp);
		}
	}
	free(G.edges);
}
Graph read_graph() {
	Graph G; // define a new graph
	scanf("%d", &G.V);// read the input.txt
	G.edges = malloc(sizeof(G.edges) * G.V);//
	//printf("%d\n", G.V); (for debugging)
	for (int i = 0; i < G.V; i++) {
		int edges_number;
		scanf("%d", &edges_number);

		// initialise a new graph new graph
		G.edges[i].head = NULL;

		//printf("%d\n", edges_number); (for debugging)

		for (int count = 0; count < edges_number; count = count + 1) {
			EdgeNodePtr edge_node = malloc(sizeof(EdgeNodePtr));

			scanf("%d,%d", &edge_node->edge.to_vertex, &edge_node->edge.weight);

			//add_edge()
			edge_node->next = G.edges[i].head;
			G.edges[i].head = edge_node;

		}
	}
	return G;
}
double pagerank(Graph G, int v, double d)
{
	double total = 0;
	for (int i = 0; i < G.V; i++)
	{
		double out = 0;
		double link = 0;
		EdgeNodePtr current = G.edges[i].head;

		while (current != NULL)
		{
			out++;
			if (current->edge.to_vertex == v)
			{
				link++;
			}
			current = current->next;
		}
		total += link / out;
	}
	return (1 - d) + d * total;
}