#pragma once
#include<iostream>
using namespace std;
struct Matrix33
{
	int value[3][3];

};
Matrix33 operator*(const int & k, const Matrix33& m);
Matrix33 operator*(const Matrix33& m, const Matrix33& n);
ostream& operator<<(ostream& os, const Matrix33 & m);