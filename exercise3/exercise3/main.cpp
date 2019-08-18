#include <iostream>
#include"Sweep.h"
using namespace std;

void GameLoop(SweepingBombs& a) {
	int x, y;
	while (1) {
		cout << "Enter The Row And Col(x,y)"<<endl;
			cin >> x >> y;
			if (!a.Play(x, y)) {
				a.Print();
				break;
			}
			a.Print();
	}
}
void GameInit(SweepingBombs& a) {

}
int main(int argc, char* argv[])
{
	SweepingBombs a(8,10);
	cout << "PleaseEnterTheLevelOfTheGame(EASY:1|NORMAL:2|HARD:3):"<<endl;
	int temp;
	cin >> temp;
	switch (temp)
	{
	case 1:
		a.ResetLevel(DIFFICULT_LEVEL_EASY);
		break;
	case 2:
		a.ResetLevel(DIFFICULT_LEVEL_NORMAL);
		break;
	case 3:
		a.ResetLevel(DIFFICULT_LEVEL_HARD);
		break;
	default:
		break;
	}
	a.Print();
	GameLoop(a);
	//cout << "¡ö*123456789£¿¡Ì";
		return 0;
}