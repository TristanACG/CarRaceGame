#pragma once
#include "Position.h"
class Car
{
private:
	char icon;
	Position position;
public:
	Car();
	Car(char icon);
	void setIcon(char icon);
	void setPosition(Position position);

	char getIcon();
	Position getPosition();
};

