#include <iostream>
#include "StringUtil.h"
/*
	≤‚ ‘”√¿˝£∫
	 ‰»Î£∫	eabceabc	 ‰≥ˆ£∫	eabc
			aaaa				a
			abacaabaca			abaca
			abccabcc			abcc
			abccd				abccd

*/

using namespace std;

void CyclicityTest();
int main() {
	CyclicityTest();
	system("pause");
	return 0;
}

void CyclicityTest() {
	string testgroup[] = {
		"eabceabc",
		"aaaa",
		"abacaabaca",
		"abccabcc",
		"abccd",
		"aba",
		"a",
		"aaca",
		"qweqweqweqweewqqwe"
	};
	for (auto str : testgroup) {
		cout << "the minimum cyclic substring of \"" << str << "\" is :  " << StringUtil::GetCyclicSubStr(str) << endl;
	}
	
}