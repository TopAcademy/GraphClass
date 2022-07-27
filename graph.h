#pragma once
#include <iostream>

// Class "Graph"
class Graph
{
private:
	// member fields
	int** matrix;
	unsigned node_count;
public:
	// constructor & destructor
	Graph(unsigned n_count);
	~Graph();
	// getters
	void show_matrix() const;
	// setters
	void add_edge(int node1, int node2);
	void add_oriented_edge(int node1, int node2);
	void add_edge_with_weight(int node1, int node2, int weight);

};

// Constructors 
Graph::Graph(unsigned n_count)
{
	if (n_count < 2) throw 1;
	this->node_count = n_count;
	matrix = new int* [n_count+1];
	int i, j;
	for (i = 0; i <= n_count; i++) {
		matrix[i] = new int[n_count+1];
		for (j = 0; j <= n_count; j++) matrix[i][j] = 0;
	}
}

Graph::~Graph()
{
	for (int i = 0; i <= this->node_count; i++)
		delete[] matrix[i];
	delete[] matrix;
}

// Print the matrix on console screen
void Graph::show_matrix() const
{
	int i, j;
	for (i = 1; i <= node_count; i++) {
		for (j = 1; j <= node_count; j++)
			std::cout << matrix[i][j] << ' ';
		std::cout << std::endl;
	}
}

// Set new edge between 2 nodes
void Graph::add_edge(int node1, int node2)
{
	matrix[node1][node2] = 1;
	matrix[node2][node1] = 1;
}

// Set new ORIENTED edge between 2 nodes
void Graph::add_oriented_edge(int node1, int node2)
{
	matrix[node1][node2] = 1;
}

void Graph::add_edge_with_weight(int node1, int node2, int weight)
{
	matrix[node1][node2] = weight;
}