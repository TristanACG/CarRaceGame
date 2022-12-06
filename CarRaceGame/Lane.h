#pragma once
#include "Car.h"
#include "Position.h"
#include <string>
using namespace std;

class Lane
{
private:
	int LBnd;
	int Cntr;
	int RBnd;
	Car car;
	string name;
public:
	Lane();
	Lane(int lbnd, int cntr, int rbnd, Car car, string name);

	void setLBnd(int lbnd);
	void setCntr(int cntr);
	void setRBnd(int rbnd);
	void setCar(Car car);

	int getLBnd();
	int getCntr();
	int getRBnd();
	Car* getCar();
	string getName();
};

