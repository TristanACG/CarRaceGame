#include "Car.h"

Car::Car() {};

Car::Car(char icon)
{
	this->icon = icon;
}

void Car::setIcon(char icon)
{
	this->icon = icon;
}
void Car::setPosition(Position position)
{
	this->position = position;
}

char Car::getIcon()
{
	return icon;
}
Position Car::getPosition()
{
	return position;
}
