#pragma once
#include <iostream>
using namespace std;
class coordinate
{
public:
	coordinate();
	coordinate(unsigned m, unsigned n);
	void setx(unsigned i);
	unsigned getx();
	void sety(unsigned i);
	unsigned gety();
	void addx();//����ı�
	void reducex();
	void addy();
	void reducey();
	void print();
	~coordinate();
private:
	unsigned x, y;
};
