#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

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

int** merge_vertexes_matrix(int** g, int size, int first, int second);
int** edge_contraction_matrix(int** g, int size, int first, int second);
int** delete_vertex_matrix(int** g, int size, int vertex);

struct Graph* create_adjacency_list(int vertexes);
struct Node* create_vertex(int vertex);
void connect_vertexes(struct Graph* graph, int coll, int dest, bool pattern);
void cout_adjacency_list(struct Graph* graph);

void merge_vertexes_list(Graph* graph, int first, int second);
void edge_contraction_list(Graph* graph, int first, int second);
void delete_vertex_list(Graph* graph, int vertex);

void main()
{
	int size_M1 = 0, size_M2 = 0, to_start_with = 0, first_act = 0, second_act = 0;
	cout << "Input first graph size: ";
	cin >> size_M1;
	int** M1 = create_adjacency_matrix(size_M1);
	cout_matrix(M1, size_M1);

	int choise = 0;
	bool stop_flag = 0;
	while (!stop_flag) 
	{
		first_act = 0, second_act = 0, choise = 0;
		cout << "Choose action:" << endl << "1 - Merge vertexes | 2 - Contract edge | 3 - Delete vertex | 4 - Exit " << endl; 
		cin >> choise;
		switch (choise) 
		{
			case 1: 
			{
				cout << "Input number of the first vertex to merge: "; cin >> first_act;
				cout << "Input number of the second vertex to merge: "; cin >> second_act;
				if (first_act >= size_M1 || second_act >= size_M1 || first_act < 0 || second_act < 0)
				{
					cout << "Error: Vertex numbers must be between 0 and " << size_M1 - 1 << endl;
				}
				else if (first_act == second_act)
				{
					cout << "Error: The vertices must be different." << endl;
				}
				else 
				{
					M1 = merge_vertexes_matrix(M1, size_M1, 1, 2);
					size_M1--;
					cout_matrix(M1, size_M1);
				}
				continue;
			}
			case 2: 
			{
				cout << "Input number of the first vertex to contract: "; cin >> first_act;
				cout << "Input number of the second vertex to contract: "; cin >> second_act;

				if (first_act >= size_M1 || second_act >= size_M1 || first_act < 0 || second_act < 0) 
				{
					cout << "Error: Vertex numbers must be between 0 and " << size_M1 - 1 << endl;
				}
				else if (first_act == second_act)
				{
					cout << "Error: The vertices must be different." << endl;
				}
				else if (M1[first_act][second_act] == 0)
				{
					cout << "Error: Edge does not exist." << endl;
				}
				else
				{
					M1 = edge_contraction_matrix(M1, size_M1, first_act, second_act);
					size_M1--;
					cout_matrix(M1, size_M1);
				}
				continue;
			}
			case 3:
			{
				cout << "Input the vertex to delete: "; cin >> first_act;
				if (first_act > size_M1 || first_act < 0)
				{
					cout << "Error: Vertex number must be between 0 and " << size_M1 - 1 << endl;
				}
				else
				{
					M1 = delete_vertex_matrix(M1, size_M1, first_act);
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
				cout << "Error: Please choose a valid option (1-4)." << endl;
				continue;
			}
		}
	}



	struct Graph* L1 = create_adjacency_list(size_M1);
	for (int i = 0; i < size_M1; i++)
	{
		for (int j = 0; j < size_M1; j++)
		{
			if (M1[i][j] == 1)
			{
				connect_vertexes(L1, i, j, 0);
			}
		}
	}
	cout_adjacency_list(L1);

	choise = 0, stop_flag = 0;
	while (!stop_flag) 
	{
		first_act = 0, second_act = 0, choise = 0;
		cout << "Choose action:" << endl << "1 - Merge vertexes | 2 - Contract edge | 3 - Delete vertex | 4 - Exit " << endl;
		cin >> choise;
		switch (choise)
		{
		case 1: 
		{
			cout << "Input number of the first vertex to merge: "; cin >> first_act;
			cout << "Input number of the second vertex to merge: "; cin >> second_act;
			if (first_act >= size_M1 || second_act >= size_M1 || first_act < 0 || second_act < 0) 
			{
				cout << "Error: Vertex numbers must be between 0 and " << size_M1 - 1 << endl;
			}
			else if (first_act == second_act) 
			{
				cout << "Error: The vertices must be different." << endl;
			}
			else 
			{
				merge_vertexes_list(L1, first_act, second_act);
				size_M1--;
				cout_adjacency_list(L1);
			}
			break;
		}
		case 2: 
		{
			cout << "Input number of the first vertex to contract: "; cin >> first_act;
			cout << "Input number of the second vertex to contract: "; cin >> second_act;

			if (first_act >= size_M1 || second_act >= size_M1 || first_act < 0 || second_act < 0) 
			{
				cout << "Error: Vertex numbers must be between 0 and " << size_M1 - 1 << endl;
			}
			else if (first_act == second_act) 
			{
				cout << "Error: The vertices must be different." << endl;
			}
			else if (M1[first_act][second_act] == 0)
			{
				cout << "Error. Edge does not exist." << endl;
			}
			else 
			{
				edge_contraction_list(L1, first_act, second_act);
				size_M1--;
				cout_adjacency_list(L1);
			}
			break;
		}
		case 3: 
		{
			cout << "Input the vertex to delete: "; cin >> first_act;

			if (first_act >= size_M1 || first_act < 0) 
			{
				cout << "Error: Vertex number must be between 0 and " << size_M1 - 1 << endl;
			}
			else 
			{
				delete_vertex_list(L1, first_act);
				size_M1--;
				cout_adjacency_list(L1);
			}
			break;
		}
		case 4: 
		{
			stop_flag = 1;
			break;
		}
		default: 
		{
			cout << "Error: Please choose a valid option (1-4)." << endl;
			break;
		}
		}
	}



	cout << endl << "---------------------------------" << endl;
	delete[]M1;
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

int** merge_vertexes_matrix(int** g, int size, int first, int second)
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

	g = delete_vertex_matrix(g, size, second);

	return g;
}

int** edge_contraction_matrix(int** g, int size, int first, int second) 
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

	g = delete_vertex_matrix(g, size, second);
	return g;
}

int** delete_vertex_matrix(int** g, int size, int vertex)
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

void connect_vertexes(struct Graph* graph, int coll, int dest, bool pattern)
{
	struct Node* new_node = create_vertex(dest);
	int i = 0;
	if (pattern == 0)
	{
		while (graph->list[i]->vertex != coll)
		{
			i++;
		}
	}
	else if (pattern == 1) 
	{
		i = coll;
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

void merge_vertexes_list(Graph* graph, int first, int second) 
{
	Node* second_vertex = graph->list[second];
	while (second_vertex->next != nullptr) 
	{
		connect_vertexes(graph, first, second_vertex->next->vertex, 0);
		second_vertex = second_vertex->next;
	}

	for (int i = 0; i < graph->vertexes_amount; i++) 
	{
		Node* temp = graph->list[i];
		while (temp != nullptr) 
		{
			if (temp->next != nullptr && temp->next->vertex == second) 
			{
				connect_vertexes(graph, i, first, 0);
				Node* to_delete = temp->next;
				temp->next = temp->next->next;
				delete to_delete;
			}
			temp = temp->next;
		}
	}

	delete_vertex_list(graph, second);	
	
	for (int i = 0; i < graph->vertexes_amount; i++)
	{
		vector<int> vertexes;
		vector<int> ::iterator res;
		Node* tmp = graph->list[i];
		if (tmp->next != nullptr)
		{
			int main_v = tmp->vertex;
			tmp = tmp->next;
			while (tmp != nullptr)
			{
				vertexes.push_back(tmp->vertex);
				tmp = tmp->next;
			}
			sort(vertexes.begin(), vertexes.end());
			res = unique(vertexes.begin(), vertexes.end());
			vertexes.resize(res - vertexes.begin());
		}
		graph->list[i]->next = nullptr;
		for (const auto v : vertexes)
		{
			connect_vertexes(graph, i, v, 1);
		}
	}
}

void edge_contraction_list(Graph* graph, int first, int second) 
{
	bool loop = 0;
	Node* tmptmptmp = graph->list[first];
	tmptmptmp = tmptmptmp->next;
	while (tmptmptmp != nullptr)
	{
		if (tmptmptmp->vertex == first)
		{
			loop = 1;
		}
		tmptmptmp = tmptmptmp->next;
	}
	Node* second_vertex = graph->list[second];
	while (second_vertex->next != nullptr)
	{
		connect_vertexes(graph, first, second_vertex->next->vertex, 0);
		second_vertex = second_vertex->next;
	}

	for (int i = 0; i < graph->vertexes_amount; i++)
	{
		Node* temp = graph->list[i];
		while (temp != nullptr)
		{
			if (temp->next != nullptr && temp->next->vertex == second)
			{
				connect_vertexes(graph, i, first, 0);
				Node* to_delete = temp->next;
				temp->next = temp->next->next;
				delete to_delete;
			}
			temp = temp->next;
		}
	}

	delete_vertex_list(graph, second);

	for (int i = 0; i < graph->vertexes_amount; i++)
	{
		vector<int> vertexes;
		vector<int> ::iterator res;
		Node* tmp = graph->list[i];
		if (tmp->next != nullptr)
		{
			int main_v = tmp->vertex;
			tmp = tmp->next;
			while (tmp != nullptr)
			{
				vertexes.push_back(tmp->vertex);
				tmp = tmp->next;
			}
			sort(vertexes.begin(), vertexes.end());
			res = unique(vertexes.begin(), vertexes.end());
			vertexes.resize(res - vertexes.begin());
			if (i == first && loop != 1)
			{
				vector<int> ::iterator ers;
				for (int z : vertexes)
				{
					if (z == first) 
					{
						ers = vertexes.begin() + z;
					}
				}
				vertexes.erase(ers);
			}
		}
		graph->list[i]->next = nullptr;
		for (const auto v : vertexes)
		{
			connect_vertexes(graph, i, v, 1);
		}
	}
}

void delete_vertex_list(Graph* graph, int vertex)
{
	for (int i = 0; i < graph->vertexes_amount; i++)
	{
		Node* temp = graph->list[i];
		while (temp != nullptr && temp->next != nullptr)
		{
			if (temp->next->vertex == vertex)
			{
				Node* to_delete = temp->next;
				temp->next = temp->next->next;
				delete to_delete;
			}
			else
			{
				temp = temp->next;
			}
		}
	}

	Node* temp = graph->list[vertex];
	while (temp != nullptr)
	{
		Node* to_delete = temp;
		temp = temp->next;
		delete to_delete;
	}

	graph->list[vertex] = nullptr;

	for (int i = vertex; i < graph->vertexes_amount - 1; i++)
	{
		graph->list[i] = graph->list[i + 1];
	}

	graph->list[graph->vertexes_amount - 1] = nullptr;
	graph->vertexes_amount--;
}