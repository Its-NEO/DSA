#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class WeightedGraph 
{
	private:
		int** ad_mat;
		int SIZE;

	public:
		WeightedGraph(int SIZE) : SIZE {SIZE} {
			ad_mat = new int*[SIZE];

			for (int i = 0; i < SIZE; i++)
				ad_mat[i] = new int[SIZE];
		}

		WeightedGraph() : WeightedGraph(100) {}

		~WeightedGraph() {
			for (int i = 0; i < SIZE; i++)
				delete[] ad_mat[i];
			
			delete[] ad_mat;
		}

		void add_vertex(int vertex, int connected_to, int edge_weight);
		void remove_vertex(int element);

		std::vector<int> get_connected(int vertex);
		int get_edge_weight(int vertexA, int vertexB)
		{
			return ad_mat[vertexA][vertexB];
		}

		void info(); 
};

void WeightedGraph::add_vertex(int vertex, int connected_to, int edge_weight)
{
	ad_mat[vertex][connected_to] = edge_weight;
	ad_mat[connected_to][vertex] = edge_weight;
}

void WeightedGraph::remove_vertex(int vertex)
{
	for (int i = 0; i < SIZE; i++)
	{
		ad_mat[vertex][i] = 0;
		ad_mat[i][vertex] = 0;
	}
}

void WeightedGraph::info() {
	std::cout << "Adjacency Matrix: \n";
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			std::cout << ad_mat[i][j] << "  ";
		}

		std::cout << '\n';
	}

	std::cout << '\n';
	std::cout << "Connected to: \n";

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << i << " -> {";
		for (int j = 0; j < SIZE; j++)
		{
			if (ad_mat[i][j] == 1)
			{
				std::cout << j << ", ";
			}
		}

		std::cout << "}" << std::endl;
	}
}

std::vector<int> WeightedGraph::get_connected(int vertex)
{
	std::vector<int> out;

	for (int i = 0; i < SIZE; i++)
	{
		if (ad_mat[vertex][i] != 0)
			out.push_back(i);
	}

	return out;
}


int main()
{
	WeightedGraph graph {10};
	graph.add_vertex(2, 5, 4);
	graph.add_vertex(2, 6, 2);

	for (auto i : graph.get_connected(2))
		std::cout << i << '\n';

	std::cout << graph.get_edge_weight(2, 5);
	return 0;
}
