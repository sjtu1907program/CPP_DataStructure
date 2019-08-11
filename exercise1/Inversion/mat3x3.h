#pragma once
#include <iostream>

struct mat3x3
{
	double v[3][3];
};

mat3x3 multiply(const mat3x3& m, const mat3x3& n);
mat3x3 multiply(const mat3x3& m, double k);
mat3x3 add(const mat3x3& m, const mat3x3& n);
mat3x3 sub(const mat3x3& m, const mat3x3& n);
std::ostream& operator<< (std::ostream& os, const mat3x3& m);