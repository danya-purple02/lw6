#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Node
{
	int vertex;
	struct Node* next;
};

struct Graph
{
	int vertexes_amount;
	struct Node** list;
};

int** create_adjacency_matrix(int v);
int cout_matrix(int** G, int v);

struct Graph* create_adjacency_list(int vertexes);
struct Node* create_vertex(int vertex);
void connect_vertexes(struct Graph* graph, int coll, int dest);
void cout_adjacency_list(struct Graph* graph);

void main()
{
	int size_M1 = 0, size_M2 = 0, to_start_with;
	cout << "input first graph size: ";
	cin >> size_M1;
	int** M1 = create_adjacency_matrix(size_M1);
	cout_matrix(M1, size_M1);

	struct Graph* L1 = create_adjacency_list(size_M1);
	for (int i = 0; i < size_M1; i++)
	{
		for (int j = 0; j < size_M1; j++)
		{
			if (M1[i][j] == 1)
			{
				connect_vertexes(L1, i, j);
			}
		}
	}
	cout_adjacency_list(L1);

	cout << endl << "---------------------------------" << endl;



	cout << "input second graph size: ";
	cin >> size_M2;
	int** M2 = create_adjacency_matrix(size_M2);
	cout_matrix(M2, size_M2);

	struct Graph* L2 = create_adjacency_list(size_M2);
	for (int i = 0; i < size_M2; i++)
	{
		for (int j = 0; j < size_M2; j++)
		{
			if (M2[i][j] == 1)
			{
				connect_vertexes(L2, i, j);
			}
		}
	}
	cout_adjacency_list(L2);

	cout << endl << "---------------------------------" << endl;



	delete[]M1;
	delete[]M2;
	return;
}

int** create_adjacency_matrix(int v)
{
	srand(time(NULL));
	int** G = new int* [v];

	for (int i = 0; i < v; i++)
	{
		G[i] = new int[v];
	}

	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			if (j < i)
			{
				G[i][j] = G[j][i];
			}
			else
			{
				G[i][j] = rand() % 2;
			}
		}
	}

	return G;
}

int cout_matrix(int** g, int v)
{
	cout << "    ";
	for (int i = 0; i < v; i++)
	{
		cout << i << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < v; i++)
	{
		cout << i << "   ";
		for (int j = 0; j < v; j++)
		{
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	return 1;
}



struct Graph* create_adjacency_list(int vertexes)
{
	struct Graph* graph = new struct Graph;
	graph->vertexes_amount = vertexes;
	graph->list = new struct Node* [vertexes];
	for (int i = 0; i < vertexes; i++)
	{
		graph->list[i] = new struct Node[vertexes];
	}

	for (int i = 0; i < vertexes; i++)
	{
		graph->list[i] = create_vertex(i);
	}

	return graph;
}

struct Node* create_vertex(int vertex)
{
	struct Node* new_node = new struct Node;
	new_node->vertex = vertex;
	new_node->next = NULL;
	return new_node;
}

void connect_vertexes(struct Graph* graph, int coll, int dest)
{
	struct Node* new_node = create_vertex(dest);
	int i = 0;
	while (graph->list[i]->vertex != coll)
	{
		i++;
	}

	struct Node* tmp = graph->list[i];
	while (tmp->next != NULL)
	{

		tmp = tmp->next;
	}

	tmp->next = new_node;
}

void cout_adjacency_list(struct Graph* graph)
{
	cout << endl << "adjacency list:" << endl;
	struct Node* tmp;
	for (int i = 0; i < graph->vertexes_amount; i++)
	{
		tmp = graph->list[i];
		while (tmp)
		{
			cout << tmp->vertex;
			tmp = tmp->next;
			if (tmp != NULL)
			{
				cout << " -> ";
			}
		}
		cout << endl;
	}
}