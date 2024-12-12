#define _CRT_SEcuRE_NO_WARNINGS

#include <iostream>

using namespace std;

int** create_adjacency_matrix(int v);
int cout_matrix(int** G, int v);

int** graph_union_matrix(int** M1, int size_M1, int** M2, int size_M2);
int** graph_intersection_matrix(int** M1, int size_M1, int** M2, int size_M2);
int** graph_ring_sum_matrix(int** M1, int size_M1, int** M2, int size_M2);

void main() 
{
	int size_M1 = 0, size_M2 = 0, to_start_with = 0, first_act = 0, second_act = 0;
	cout << "Input first graph size: ";
	cin >> size_M1;
	
	cout << "Input second graph size: ";
	cin >> size_M2;

	int** M1 = create_adjacency_matrix(size_M1);
	cout_matrix(M1, size_M1);
	int** M2 = create_adjacency_matrix(size_M2);
	cout_matrix(M2, size_M2);

	int** M_union = graph_union_matrix(M1, size_M1, M2, size_M2);
	cout << "Union of Graphs:\n";
	cout_matrix(M_union, max(size_M1, size_M2));

	int** M_intersection = graph_intersection_matrix(M1, size_M1, M2, size_M2);
	cout << "Intersection of Graphs:\n";
	cout_matrix(M_intersection, max(size_M1, size_M2));

	int** M_ring_sum = graph_ring_sum_matrix(M1, size_M1, M2, size_M2);
	cout << "Ring Sum of Graphs:\n";
	cout_matrix(M_ring_sum, max(size_M1, size_M2));

	for (int i = 0; i < size_M1; i++) 
	{
		delete[] M1[i];
	}
	delete[] M1;

	for (int i = 0; i < size_M2; i++) 
	{
		delete[] M2[i];
	}
	delete[] M2;

	for (int i = 0; i < max(size_M1, size_M2); i++) 
	{
		delete[] M_union[i];
		delete[] M_intersection[i];
		delete[] M_ring_sum[i];
	}
	delete[] M_union;
	delete[] M_intersection;
	delete[] M_ring_sum;
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

int** graph_union_matrix(int** M1, int size_M1, int** M2, int size_M2) 
{
	int max_size = max(size_M1, size_M2);
	int** M_union = new int* [max_size];

	for (int i = 0; i < max_size; i++) 
	{
		M_union[i] = new int[max_size];
		for (int j = 0; j < max_size; j++) 
		{
			int val1 = (i < size_M1 && j < size_M1) ? M1[i][j] : 0;
			int val2 = (i < size_M2 && j < size_M2) ? M2[i][j] : 0;
			M_union[i][j] = val1 || val2;
		}
	}
	return M_union;
}

int** graph_intersection_matrix(int** M1, int size_M1, int** M2, int size_M2)
{
	int max_size = max(size_M1, size_M2);
	int** M_intersection = new int* [max_size];

	for (int i = 0; i < max_size; i++) 
	{
		M_intersection[i] = new int[max_size];
		for (int j = 0; j < max_size; j++) 
		{
			int val1 = (i < size_M1 && j < size_M1) ? M1[i][j] : 0;
			int val2 = (i < size_M2 && j < size_M2) ? M2[i][j] : 0;
			M_intersection[i][j] = val1 && val2;
		}
	}

	return M_intersection;
}

int** graph_ring_sum_matrix(int** M1, int size_M1, int** M2, int size_M2)
{
	int max_size = max(size_M1, size_M2);
	int** M_ring_sum = new int* [max_size];

	for (int i = 0; i < max_size; i++) 
	{
		M_ring_sum[i] = new int[max_size];
		for (int j = 0; j < max_size; j++) 
		{
			int val1 = (i < size_M1 && j < size_M1) ? M1[i][j] : 0;
			int val2 = (i < size_M2 && j < size_M2) ? M2[i][j] : 0;
			M_ring_sum[i][j] = val1 ^ val2;
		}
	}

	return M_ring_sum;
}