#define _CRT_SEcuRE_NO_WARNINGS

#include <iostream>

using namespace std;

int** create_adjacency_matrix(int v);
int cout_matrix(int** G, int v);
int** cartesian_product_matrix(int** M1, int size_M1, int** M2, int size_M2);

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
	
	int** result = cartesian_product_matrix(M1, size_M1, M2, size_M2);

	cout << "Cartesian Product Matrix:" << endl;
	cout_matrix(result, size_M1 * size_M2);
	
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

	for (int i = 0; i < size_M1 * size_M2; i++)
	{
		delete[] result[i];
	}
	delete[] result;

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

int** cartesian_product_matrix(int** M1, int size_M1, int** M2, int size_M2)
{
	if (M1 == nullptr || M2 == nullptr)
	{
		throw invalid_argument("One of the matrices is null.");
	}
	if (size_M1 <= 0 || size_M2 <= 0)
	{
		throw invalid_argument("Matrix sizes must be greater than zero.");
	}

	int size_product = size_M1 * size_M2;

	int** result = new int* [size_product];
	for (int i = 0; i < size_product; i++)
	{
		result[i] = new int[size_product]();
	}

	for (int i1 = 0; i1 < size_M1; i1++)
	{
		for (int j1 = 0; j1 < size_M1; j1++)
		{
			for (int i2 = 0; i2 < size_M2; i2++)
			{
				for (int j2 = 0; j2 < size_M2; j2++)
				{
					int row = i1 * size_M2 + i2; // result matrix raw index
					int col = j1 * size_M2 + j2; // result matrix col index

					if ((i1 == j1 && M2[i2][j2] == 1) || (i2 == j2 && M1[i1][j1] == 1))
					{
						result[row][col] = 1;
					}
				}
			}
		}
	}

	return result;
}