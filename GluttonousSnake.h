#pragma once
#include <iostream>
#include <vector>
#include "coordinate.h"
#include "snake.h"
using namespace std;
class GluttonousSnake 
:public snake
{
public:
	GluttonousSnake();//��ʼ��
	int Gluttonous(coordinate m);//�߼ӳ�
	void move(char m);//���ƶ�
	void eatmove(char m);//�߳Է�ʱ�ƶ�
	~GluttonousSnake();
};

