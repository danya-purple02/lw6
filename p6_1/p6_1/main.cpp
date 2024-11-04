#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int** create_adjacency_matrix(int vertexes);
int cout_matrix(int vertexes, int** G);

void main() 
{
	int vertexes_M1 = 0, vertexes_M2 = 0;
	cout << "input graph size: ";
	cin >> vertexes_M1;
	cout << endl;
	
	cout << "input graph size: ";
	cin >> vertexes_M2;
	cout << endl;

	int** M1 = create_adjacency_matrix(vertexes_M1);
	if (!cout_matrix(vertexes_M1, M1)) 
	{
		cout << "adjacency matrix M1 was not created" << endl;
	}

	int** M2 = create_adjacency_matrix(vertexes_M2);
	if (!cout_matrix(vertexes_M2, M2))
	{
		cout << "adjacency matrix was not created" << endl;
	}

	delete[]M1;
	delete[]M2;
	return;
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
	cout << endl << "    ";
	for (int i = 1; i <= vertexes; i++)
	{
		cout << i << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < vertexes; i++)
	{
		cout << i + 1 << "   ";
		for (int j = 0; j < vertexes; j++)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
	return 1;
}