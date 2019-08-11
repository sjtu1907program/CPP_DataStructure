#include <iostream>
#include "mat3x3.h"
#include "List.h"

using namespace std;

bool checkbit(unsigned m, char k)
{
	return ( m & (1<<k));
}

void Inversion(int* v, int size)// int v[]
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (v[i] > v[j])
			{
				cout << "(" << v[i] << "," << v[j] <<")" << endl;
			}
		}
	}
}

void MatMult(int m[][3], int n[][3], int rows)
{
	for (int i = 0; i < rows ; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			int result{};
			result = m[i][0] * n[0][j] + m[i][1] * n[1][j] + m[i][2] * n[2][j];
			cout<< result << ", ";
		}
		cout << endl;
	}
}

int Round(float v)
{
	return v <=0 ? v - 0.5f : v + 0.5f;
}

void TestLinkList()
{
	int v[] = { 1, 2, 3, 4, 3 };
	LinkList lst(v, 4);
	// 1->2 ->3 -> 4 -> 3 
	cout << lst << endl;
	lst.erase(3);
	cout << lst.size() << endl;
	cout << lst << endl;
	lst.insert(nullptr, 10);
	auto node = lst.find(2);
	lst.insert(node, 8);
	cout << lst << endl;
}

int  main() 
{
	TestLinkList();

	int a1 = Round(-7.2f);
	int a2 = Round(-7.8f);
	auto r = checkbit(0x7, 2);

	int v[] = { 6, 5, 7, 3, 10, 4 };

	int* p = v;

	int size = sizeof(v)/sizeof(int);


	int mat[3][3] =
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	int n[3][3] =
	{
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};

	mat3x3 mat3 =
	{
		{
		{1,2,3},
		{4,5,6},
		{7,8,9}
		}
	};

	mat3x3 n3 =
	{
		{
		{1,1,1},
		{1,1,1},
		{1,1,1}
		}
	};

	
	cout << multiply(mat3,n3)<< endl;
	cout << multiply(mat3, 6) << endl;
	cout << add(mat3, n3)<< endl;
	cout << sub(mat3, n3) << endl;

	MatMult(mat, n, 3);
 	Inversion(p,size);
	return 0;
}


