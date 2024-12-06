#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int** create_adjacency_matrix(int v);
int cout_matrix(int** G, int v);

void main()
{
	int size_M1 = 0, size_M2 = 0, to_start_with;
	cout << "input first graph size: ";
	cin >> size_M1;
	int** M1 = create_adjacency_matrix(size_M1);
	cout_matrix(M1, size_M1);
	cout << endl << "---------------------------------" << endl;


	cout << "input second graph size: ";
	cin >> size_M2;
	int** M2 = create_adjacency_matrix(size_M2);
	cout_matrix(M2, size_M2);
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