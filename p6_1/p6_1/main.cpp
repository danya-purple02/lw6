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
int** create_adjacency_matrix(int vertexes);
int cout_matrix(int vertexes, int** G);
struct Graph* create_adjacency_list(int vertexes);
struct Node* create_vertex(int vertex);
void connect_vertexes(struct Graph* graph, int coll, int dest); 
void cout_adjacency_list(struct Graph* graph);

void main()
{
	int vertexes_M1 = 0, vertexes_M2 = 0;
	cout << "input graph G1 size: ";
	cin >> vertexes_M1;
	cout << endl;

	int** M1 = create_adjacency_matrix(vertexes_M1);
	if (!cout_matrix(vertexes_M1, M1))
	{
		cout << "adjacency matrix M1 was not created" << endl;
	}


	struct Graph* G1 = create_adjacency_list(vertexes_M1);
	for (int i = 0; i < vertexes_M1; i++) 
	{
		for (int j = 0; j < vertexes_M1; j++) 
		{
			if (M1[i][j] == 1)
			{
				connect_vertexes(G1, i, j);
			}
		}
	}

	cout_adjacency_list(G1);

	cout << endl << "---------------------------------" << endl;
	cout << "input graph G2 size: ";
	cin >> vertexes_M2;
	cout << endl;

	int** M2 = create_adjacency_matrix(vertexes_M2);
	if (!cout_matrix(vertexes_M2, M2))
	{
		cout << "adjacency matrix was not created" << endl;
	}

	struct Graph* G2 = create_adjacency_list(vertexes_M2);
	for (int i = 0; i < vertexes_M2; i++)
	{
		for (int j = 0; j < vertexes_M2; j++)
		{
			if (M2[i][j] == 1)
			{
				connect_vertexes(G2, i, j);
			}
		}
	}
	cout_adjacency_list(G2);

	delete[]M1;
	delete[]M2;
	return;
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

int** create_adjacency_matrix(int vertexes)
{
	srand(time(NULL));
	int** G = new int* [vertexes];
	for (int i = 0; i < vertexes; i++)
	{
		G[i] = new int[vertexes];
	}
	for (int i = 0; i < vertexes; i++)
	{
		for (int j = 0; j < vertexes; j++)
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

int cout_matrix(int vertexes, int** G)
{
	cout << "    ";
	for (int i = 0; i < vertexes; i++)
	{
		cout << i << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < vertexes; i++)
	{
		cout << i << "   ";
		for (int j = 0; j < vertexes; j++)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
	return 1;
}