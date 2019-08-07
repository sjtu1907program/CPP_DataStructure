#include"matrix33.h"
#include<iostream>
using namespace std;

Matrix33 operator*(const int & k, const Matrix33&m)
{
	Matrix33 r;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			r.value[i][j] = k * m.value[i][j];
	return r;
}


Matrix33 operator*(const Matrix33& m, const Matrix33& n)
{
	Matrix33 r;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			r.value[j][i] = m.value[0][i] * n.value[j][0] + m.value[1][i] * n.value[j][1] + m.value[2][i] * n.value[j][2];
	return r;
}

ostream& operator<<(ostream& os, const Matrix33 & m)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			os << m.value[i][j] << ' ';
		os << endl;
;	}
	
	return os;
}
