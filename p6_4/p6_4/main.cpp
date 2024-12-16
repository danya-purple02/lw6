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

	M1[0][0] = 0; M1[0][1] = 1;
	M1[1][0] = 1; M1[1][1] = 0;

	cout_matrix(M1, size_M1);
	int** M2 = create_adjacency_matrix(size_M2);
	
	M2[0][0] = 0; M2[0][1] = 1; M2[0][2] = 1;
	M2[1][0] = 1; M2[1][1] = 0; M2[1][2] = 1;
	M2[1][0] = 1; M2[2][1] = 1; M2[2][2] = 0;
	
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
	cout << "	";
	for (int i = 0; i < v; i++)
	{
		cout << i << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < v; i++)
	{
		cout << i << "	";
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
	int size_product = size_M1 * size_M2;

	int** result = new int* [size_product];
	for (int i = 0; i < size_product; i++)
	{
		result[i] = new int[size_product]();
	}
	int row = 0;
	int col = 0;

	for (int x1 = 0; x1 < size_M1; x1++)
	{
		for (int x2 = 0; x2 < size_M2; x2++)
		{

			for (int y1 = 0; y1 < size_M1; y1++)
			{
				for (int y2 = 0; y2 < size_M2; y2++)
				{
					//int row = x1 * size_M2 + x2;
					//int col = y1 * size_M2 + y2;

					if ((x1 == y1 && M2[x2][y2] == 1) || (x2 == y2 && M1[x1][y1] == 1))
					{
						result[row][col] = 1;
					}
					col++;
				}
			}
			row++;
			col = 0;
		}
	}

	return result;
}