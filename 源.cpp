#include"base.h"

using namespace std;

 char i, p, Temp;
 bool y = true;
 int sop = 12, M = 0, N = 0;
 coordinate t[sot];
 GluttonousSnake q;
 snake *e = &q;

int main()
{
	srand(time(NULL));
	for (int I = 0; I < sot; I++)
	{
		t[I].setx(rand() % 97);
		t[I].sety(rand() % 47);
	}
	gotoxy(50, 25);
	cout << "����Y����ʼ(����e�˳�):" << endl;
	gotoxy(50, 26);
	cout << "��P��ͣ" << endl;
	gotoxy(50, 27);
	cout << "��r����" << endl;
	gotoxy(50, 28);
	cout << "������ʳ������(���15):";
	cin >> sop;
	gotoxy(76, 25);
	cin >> p;
	thread lo(run, p), g(Get);
	g.detach();
	lo.join();
	return 0;
}

