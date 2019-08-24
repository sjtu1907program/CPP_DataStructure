#include<iostream>
#include<string>
using namespace std;
string ModelSearch(string s) {
	int stringlength = s.size();
	if (stringlength <= 1)return s;
	int modellength = 1;
	for (; modellength != (stringlength / 2 + 1); modellength++) {//长度高于一半
		if (s.substr(0, modellength) != ModelSearch(s.substr(modellength))) {
			continue;
		}
		else {
			return ModelSearch(s.substr(modellength));
		}
	}
	if (modellength == (stringlength / 2 + 1)) {
		return s;
	}


}

int main() {

	cout <<"eabceabc=>  "<< ModelSearch("eabceabc") << endl;//eabc
	cout << "aaaa=>  " << ModelSearch("aaaa") << endl;//a
	cout << "abababab=>  " << ModelSearch("abababab") << endl;
	cout << "abaaaabaaa=>  " << ModelSearch("abaaaabaaa") << endl;//abaaa
	cout << "abccabcc=>  " << ModelSearch("abccabcc") << endl;//abcc
	cout << "abccd=>  " << ModelSearch("abccd") << endl;//abccd

}