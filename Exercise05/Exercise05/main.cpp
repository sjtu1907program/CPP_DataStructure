#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	vector<int> a0 = { 2000, 5000, 3000, 1000 };
	vector<int> a1 = { 3000, 4000, 7000 };

	// sort: nlog(n) * 2
	sort(a0.begin(), a0.end(), greater<int>());
	sort(a1.begin(), a1.end(), less<int>());

	int com = 5000;
	queue<int> ans;

	// scan: for a0, look for a1
	// at most 2 * n
	int p0 = 0;
	int p1 = 0;

	while (p0 != a0.size() && p1 != a1.size()) {
		int delta = com - (a0[p0] + a1[p1]);
		if (delta < 0) {
			p0++;
		}
		else if (delta == 0)
		{
			ans.push(a0[p0]);
			p0++;
			p1++;
		}
		else {
			p1++;
		}
	}

	cout << "{ ";
	while (!ans.empty()) {
		cout << "{ " << ans.front() << ", "
			<< com - ans.front() << " }";
		ans.pop();

		if (!ans.empty()) {
			cout << ", ";
		}
	}
	cout << "  }" << endl;

	return 0;
}