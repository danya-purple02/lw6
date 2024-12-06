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

int** merge_vertexes(int** g, int size, int first, int second);
int** edge_contraction(int** g, int size, int first, int second);
int** delete_vertex(int** g, int size, int vertex);



/*struct Graph* create_adjacency_list(int vertexes);
struct Node* create_vertex(int vertex);
void connect_vertexes(struct Graph* graph, int coll, int dest);
void cout_adjacency_list(struct Graph* graph);*/

void main()
{
	int size_M1 = 0, size_M2 = 0, to_start_with = 0, first_act = 0, second_act = 0;
	cout << "input first graph size: ";
	cin >> size_M1;
	int** M1 = create_adjacency_matrix(size_M1);
	cout_matrix(M1, size_M1);
	
	int choise = 0;
	bool stop_flag = 0;
	while (!stop_flag) 
	{
		first_act = 0, second_act = 0, choise = 0;
		cout << "choose action:" << endl << "1 - merge vertexes | 2 - contract edge | 3 - delete vertex | 4 - break " << endl;
		cin >> choise;
		switch (choise) 
		{
			case 1: 
			{
				cout << "input number of first vertex to merge: "; cin >> first_act;
				cout << "input number of second vertex to merge: "; cin >> second_act;
				if (first_act > second_act)
				{
					cout << "error." << endl << "first number of vertex must be lower than second." << endl << endl;
				}
				else if (first_act == second_act)
				{
					cout << "error." << endl << "first and second numbers of vertexes can not be equal." << endl << endl;
				}
				else if (first_act > size_M1 || second_act > size_M1 || first_act < 0 || second_act < 0)
				{
					cout << "error." << endl << "matrix size is " << size_M1 << endl << " -> must type 0 to " << size_M1 << endl << endl;
				}
				else 
				{
					M1 = merge_vertexes(M1, size_M1, 1, 2);
					size_M1--;
					cout_matrix(M1, size_M1);
				}
				continue;
			}
			case 2: 
			{
				cout << "input number of first vertex to contract: "; cin >> first_act;
				cout << "input number of second vertex to contract: "; cin >> second_act;

				if (first_act > second_act)
				{
					cout << "error." << endl << "first number of vertex must be lower than second." << endl << endl;
				}
				else if (first_act == second_act) 
				{
					cout << "error." << endl << "first and second numbers of vertexes can not be equal." << endl << endl;
				}
				else if (M1[first_act][second_act] == 0)
				{
					cout << "error." << endl << "edge does not exist." << endl;
				}
				else if (first_act > size_M1 || second_act > size_M1 || first_act < 0 || second_act < 0)
				{
					cout << "error." << endl << "matrix size is " << size_M1 << endl << " -> must type 0 to " << size_M1 << endl << endl;
				}
				else
				{
					M1 = edge_contraction(M1, size_M1, first_act, second_act);
					size_M1--;
					cout_matrix(M1, size_M1);
				}
				continue;
			}
			case 3:
			{
				cout << "input number of vertex to delete: "; cin >> first_act;
				if (first_act > size_M1 || first_act < 0)
				{
					cout << "error." << endl << "matrix size is " << size_M1 << endl << " -> must type 0 to " << size_M1 << endl << endl;
				}
				else
				{
					M1 = delete_vertex(M1, size_M1, first_act);
					size_M1--;
					cout_matrix(M1, size_M1);
				}
				continue;
			}
			case 4:
			{
				stop_flag = 1;
				break;
			}
			default:
			{
				cout << "must type 1 to 4." << endl;
				continue;
			}
		}
	}

	/*struct Graph* L1 = create_adjacency_list(size_M1);
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
	cout_adjacency_list(L1);*/

	cout << endl << "---------------------------------" << endl;


	
	cout << "input second graph size: ";
	cin >> size_M2;
	int** M2 = create_adjacency_matrix(size_M2);
	cout_matrix(M2, size_M2);

	choise = 0;
	stop_flag = 0;
	while (!stop_flag)
	{
		first_act = 0, second_act = 0, choise = 0;
		cout << "choose action:" << endl << "1 - merge vertexes | 2 - contract edge | 3 - delete vertex | 4 - break " << endl;
		cin >> choise;
		switch (choise)
		{
			case 1:
			{
				cout << "input number of first vertex to merge: "; cin >> first_act;
				cout << "input number of second vertex to merge: "; cin >> second_act;
				if (first_act > second_act)
				{
					cout << "error." << endl << "first number of vertex must be lower than second." << endl << endl;
				}
				else if (first_act == second_act)
				{
					cout << "error." << endl << "first and second numbers of vertexes can not be equal." << endl << endl;
				}
				else if (first_act > size_M2 || second_act > size_M2 || first_act < 0 || second_act < 0)
				{
					cout << "error." << endl << "matrix size is " << size_M2 << endl << " -> must type 0 to " << size_M2 << endl << endl;
				}
				else
				{
					M2 = merge_vertexes(M2, size_M2, 1, 2);
					size_M2--;
					cout_matrix(M2, size_M2);
				}
				continue;
			}
			case 2:
			{
				cout << "input number of first vertex to contract: "; cin >> first_act;
				cout << "input number of second vertex to contract: "; cin >> second_act;

				if (first_act > second_act)
				{
					cout << "error." << endl << "first number of vertex must be lower than second." << endl << endl;
				}
				else if (first_act == second_act)
				{
					cout << "error." << endl << "first and second numbers of vertexes can not be equal." << endl << endl;
				}
				else if (M2[first_act][second_act] == 0)
				{
					cout << "error." << endl << "edge does not exist." << endl;
				}
				else if (first_act > size_M2 || second_act > size_M2 || first_act < 0 || second_act < 0)
				{
					cout << "error." << endl << "matrix size is " << size_M2 << endl << " -> must type 0 to " << size_M2 << endl << endl;
				}
				else
				{
					M2 = edge_contraction(M2, size_M2, first_act, second_act);
					size_M2--;
					cout_matrix(M2, size_M2);
				}
				continue;
			}
			case 3:
			{
				cout << "input number of vertex to delete: "; cin >> first_act;
				if (first_act > size_M2 || first_act < 0)
				{
					cout << "error." << endl << "matrix size is " << size_M2 << endl << " -> must type 0 to " << size_M2 << endl << endl;
				}
				else
				{
					M2 = delete_vertex(M2, size_M2, first_act);
					size_M2--;
					cout_matrix(M2, size_M2);
				}
				continue;
			}
			case 4:
			{
				stop_flag = 1;
				break;
			}
			default:
			{
				cout << "must type 1 to 4." << endl;
				continue;
			}
		}
	}

	/*struct Graph* L2 = create_adjacency_list(size_M2);
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
	cout_adjacency_list(L2);*/

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

int** merge_vertexes(int** g, int size, int first, int second)
{
	for (int i = 0; i < size; i++)
	{
		if (g[second][i] == 1)
		{
			g[first][i] = g[second][i];
			g[i][first] = g[i][second];
		}
	}
	if (g[first][second] == 1)
	{
		g[first][first] = 1;
	}

	g = delete_vertex(g, size, second);

	return g;
}

int** edge_contraction(int** g, int size, int first, int second) 
{
	for (int i = 0; i < size; i++) 
	{
		if (g[second][i] == 1) 
		{
			g[first][i] = g[second][i];
			g[i][first] = g[i][second];
		}
	}
	if (g[first][second] == 1) 
	{
		g[first][first] = 0;
	}

	g = delete_vertex(g, size, second);
	return g;
}

int** delete_vertex(int** g, int size, int vertex)
{
	int** g_new = new int* [size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		g_new[i] = new int[size - 1];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((i < vertex) && (j < vertex))
			{
				g_new[i][j] = g[i][j];
			}
			if ((i > vertex) && (j > vertex))
			{
				g_new[i - 1][j - 1] = g[i][j];
			}
			if ((i > vertex) && (j < vertex))
			{
				g_new[i - 1][j] = g[i][j];
			}
			if ((i < vertex) && (j > vertex))
			{
				g_new[i][j - 1] = g[i][j];
			}
		}
	}

	delete[]g;

	return g_new;
}



/*
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
}*/