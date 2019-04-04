#include "base.h"

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Show(coordinate m)//��ӡ��
{
	gotoxy(m.getx(), m.gety());
	cout << "O";
}
void clear(coordinate m)//�����
{
	gotoxy(m.getx(), m.gety());
	cout << ' ';
}
void clearGluttonousSnake(GluttonousSnake m)//�����
{
	for (int i = m.getl() - 1; i >= 0; i--)
	{
		clear(m.getsp(i));
	}
}
void ShowGluttonousSnake(GluttonousSnake m)//��ӡ��
{
	for (int i = m.getl()-1; i >=0 ; i--)
	{
		Show(m.getsp(i));
	}
}


void showWall(int x,int y,int ll,int hh)
{

	if (y == 1||y==hh)
	{
		gotoxy(x, y);
		cout << "_";
	}
	else
	{
		gotoxy(x, y);
		cout << "|";
	}

}

void wall(int li, int h)//��ʼ��ǽ��
{
		for (int i = 0; i < li; i++)//����
		{
			showWall(i, 1,li,h);
		}
		for (int i = 1; i < h; i++)//����
		{
			showWall(1, i, li, h);
		}
		for (int i = 1; i < li; i++)//����
		{
			showWall(i, h, li, h);
		}
		for (int i = 0; i < h; i++)//����
		{
			showWall(li, i, li, h);
		}
}


void Get()
{
	while (1)
	{
		if (_kbhit())
		{
			char m;
			m = _getch();
			switch (m)//�����ƶ�(PS:��Ϊʹ��gentche/getche �õ����ַ��Ƕ�̬��ʹ��һ�ξ����)
			{
			case 'w':
				M = e->getsp(e->getl() - 1).gety();
				N = e->getsp(e->getl() - 2).gety();
				if (M - N > 0) {}//���ж�Ϊ������������
				else
				{
					i = 'w';
				}
				break;
			case 's':
				M = e->getsp(e->getl() - 1).gety();
				N = e->getsp(e->getl() - 2).gety();
				if (M - N < 0) {}//���ж�Ϊ������������
				else
				{
					i = 's';
				}
				break;
			case 'a':
				M = e->getsp(e->getl() - 1).getx();
				N = e->getsp(e->getl() - 2).getx();
				if (M - N > 0) {}//���ж�Ϊ������������
				else
				{
					i = 'a';
				}
				break;
			case 'd':
				M = e->getsp(e->getl() - 1).getx();
				N = e->getsp(e->getl() - 2).getx();
				if (M - N < 0) {}//���ж�Ϊ������������
				else
				{
					i = 'd';
				}
				break;
			case 'r':
				clearGluttonousSnake(q);
				q.reset();
				i = 'p';
				break;
			case 'p':
				Temp = i;
				i = 'p';
				
				break;
			}
		}
	}
}

void run(char p)
{
	if (p == 'Y')
	{
		system("cls");
		q.reset();
		wall(L, H);

		while (y == true)
		{
			if (i == 'p')
			{
				system("PAUSE");
				i = Temp;
				system("cls");
				wall(L, H);
				continue;
			}
			for (int I = 0; I < sop; I++)
			{
				clear(t[I]);
				Show(t[I]);
			}
			clearGluttonousSnake(q);
			q.move(i);
			ShowGluttonousSnake(q);
			Sleep(250);
			for (int I = 0; I < sop; I++)
			{
				if (q.getsp(e->getl() - 1).getx() == t[I].getx() && q.getsp(e->getl() - 1).gety() == t[I].gety())//�߳Ե�ʳ��
				{
					srand(time(NULL));
					clear(t[I]);
					q.Gluttonous(t[I]);
					t[I].setx(rand() % 97);
					t[I].sety(rand() % 47);
					q.eatmove(i);
				}
			}
			y = judge();
		}
	}
	else
	{
		if (p == 'e')
			return;
	}
	system("cls");
	gotoxy(L / 2, H / 2);
	cout << "You are lost!" << endl;
	gotoxy(L / 2, H / 2 + 1);
	system("PAUSE");
}
bool  judge()//boolδ˵���������ʱ,Ĭ�Ϸ���50
{
	for (unsigned i = 0; i < L; i++)//����
	{
		if (q.getsp(e->getl() - 1).getx() == i && q.getsp(e->getl() - 1).gety() == 1)
		{
			return false;
		}
	}
	for (unsigned i = 1; i < H; i++)//����
	{
		if (q.getsp(e->getl() - 1).getx() == 1 && q.getsp(e->getl() - 1).gety() == i)
		{
			return false;
		}
	}
	for (unsigned i = 1; i < L; i++)//����
	{
		if (q.getsp(e->getl() - 1).getx() == i && q.getsp(e->getl() - 1).gety() == H)
		{
			return false;
		}
	}
	for (unsigned i = 0; i < H; i++)//����
	{
		if (q.getsp(e->getl() - 1).getx() == L && q.getsp(e->getl() - 1).gety() == i)
		{
			return false;
		}
	}
	for (unsigned i = 0; i < e->getl() - 1; i++)//������ҧ
	{
		if (q.getsp(e->getl() - 1).getx() == q.getsp(i).getx() && q.getsp(e->getl() - 1).gety() == q.getsp(i).gety())
		{
			return false;
		}
	}
	return true;
}