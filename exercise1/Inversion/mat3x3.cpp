#include "mat3x3.h"
#include <iostream>

mat3x3 multiply(const mat3x3& m, const mat3x3& n)
{
	mat3x3 r{};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			r.v[i][j] = m.v[i][0] * n.v[0][j] + m.v[i][1] * n.v[1][j] + m.v[i][2] * n.v[2][j];
		}
	}
	return r;
}

mat3x3 multiply(const mat3x3& m, double k)
{
	mat3x3 r{};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			r.v[i][j] = m.v[i][j] * k;
		}
	}
	return r;
}

mat3x3 add(const mat3x3& m, const mat3x3& n)
{
	mat3x3 r{};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			r.v[i][j] = m.v[i][j] + n.v[i][j];
		}
	}
	return r;
}

mat3x3 sub(const mat3x3& m, const mat3x3& n)
{
	mat3x3 r{};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			r.v[i][j] = m.v[i][j] - n.v[i][j];
		}
	}
	return r;
}

std::ostream& operator<< (std::ostream& os, const mat3x3& m)
{
	mat3x3 r{};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			os << m.v[i][j] << "\t";
		}
		os << std::endl;
	}
	return os;
}