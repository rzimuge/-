#pragma once
#include <vector>
#include "coordinate.h"
using namespace std;
class snake
{
public:
	snake();
	void setl(int i);//�߼ӳ�
	void setsp(coordinate i);//�߼ӳ�
	void body();//�����ƶ�
	void reset();//����
	coordinate getsp(int i);
	int getl();
	~snake();
protected:
	int l;
	vector<coordinate> sp;
};

