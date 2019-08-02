#include <iostream>
#include <limits>

using namespace std;

int ReverseNumber(int n)
{
	long long result{};

		while (n)
		{
			
			if (numeric_limits<int>::max() - result*10 < n % 10 * 10 )
			{
				return numeric_limits<int>::max();
			}
			else
			{
				result *= 10;
				result += n % 10;
				n /= 10;
			}
		}

	return result;
}

void test(int n) 
{
	auto result = ReverseNumber(n);
	if (result == numeric_limits<int>::max())
	{
		cout << "Cannot reverse " << n << " overflow error " << endl;
	}
	else
	{
		cout << n << " -> " << result << endl;
	}

}

void main() 
{
	test(1234567899);
	test(123);
	test(-1234);	
}