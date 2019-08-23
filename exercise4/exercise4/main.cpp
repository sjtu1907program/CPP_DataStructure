#include<iostream>

using namespace std;
class RepeatWord {

public:
	// static string Process(string test) {
	  static char*  Process(string test){
		int tsize = test.size();
		if (tsize == 0)
			return NULL;
		int repeatTimes{1};//重复次数
		int length = 1;
		while (true) {
			int pos= length * repeatTimes;//现在位置
			if (pos + length > tsize) {//重复至超了
				break;
			}
			if (test.compare(0, length, test, pos, length)==0) {//相同，继续判断
				repeatTimes++;
			}
			else {
				length = pos +1;//先定性为当前位置的长度
				while (tsize%length != 0) {//寻找可整除的公倍数
					length++;
				}
				repeatTimes = 1;
			}
		}


		char * s=new char[length+1];
		s[length + 1] = '\0';
		test.copy(s, length, 0);
		return s;
		//return test.substr(0,length);
	};
};



int main() {
	string a = "asfasfasfasfasfasfasfasfasfasfsasfasfasfasfasfasf";
	//string c = RepeatWord::Process(a);
	//printf("%s\n", c);
	cout << RepeatWord::Process(a)<<endl;
	return 0;
}