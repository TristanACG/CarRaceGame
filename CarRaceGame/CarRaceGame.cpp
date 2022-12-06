#include <iostream>
#include <windows.h>
#include <vector>
#include "time.h"
using namespace std;

#include "Position.h"
#include "Lane.h"
#include "Car.h"

void setCursor(Position position);
bool gameOver = false;

const int startLine = 24;
vector<Lane*> lanes;

Car car1(206);
Car car2(219);
Car car3(64);
Car car4(156);
Car car5(178);
Car car6(94);

Lane lane1(1,10,20,car1,"Lane1");
Lane lane2(21,30,40,car2, "Lane2");
Lane lane3(41,50,60,car3, "Lane3");
Lane lane4(61,70,80,car4, "Lane4");
Lane lane5(81,90,100,car5, "Lane5");
Lane lane6(101,110,120,car6, "Lane6");

int main()
{
	lanes.push_back(&lane1);
	lanes.push_back(&lane2);
	lanes.push_back(&lane3);
	lanes.push_back(&lane4);
	lanes.push_back(&lane5);
	lanes.push_back(&lane6);

	for (Lane* pLane : lanes)
	{
		Position position(pLane->getCntr(), startLine);
		Car* car = pLane->getCar();
		car->setPosition(position);
		
		setCursor(position);
		cout << char(car->getIcon());
	}

	for (int i = 1; i <= 5; i++)
	{
		for (int j = startLine; j > 0; j--)
		{
			setCursor(Position(lanes[i]->getLBnd(), j));
			cout << "|";
		}
	}

	while (true)	//Game Loop
	{
		srand(time(0));

		for (Lane* lane : lanes)
		{	
			int jump = rand() % 4;
			int leftRight = rand() % 3;
			int lrPosNeg = rand() % 10;
			if (lrPosNeg <= 2)
			{
				leftRight *= -1;
			}
			int posNeg = rand() % 10;
			if (posNeg <= 2)
			{
				jump *= -1;
			}

			Car* car = lane->getCar();
			Position oldPosition = car->getPosition();
			setCursor(oldPosition);
			cout << " ";

			
			Position newPosition(oldPosition.col+=leftRight, oldPosition.row -= jump);

			if (newPosition.row >= startLine)
			{
				newPosition.row = startLine;
			}


			car->setPosition(newPosition);
			setCursor(newPosition);
			cout << char(car->getIcon());

			//Check for winner

			if (newPosition.row <= 0)
			{
				setCursor(Position(newPosition));
				cout << "Winner" << " " <<  lane->getName();
				gameOver = true;
				break;
			}
			//Possible to stop car that has lane violation, but allow other cars to continue racing?
			if (newPosition.col <= lane->getLBnd() || newPosition.col >= lane->getRBnd())
			{
				//Position msgPos = car->getPosition();
				//msgPos += 2;
				//setCursor(msgPos);

				setCursor(car->getPosition() += 3);
				cout << "Lane Violation: " << lane->getName();
				gameOver = true;
				break;
			}

		}
		Sleep(500);
		if (gameOver)
		{
			break;
		}
	}

}

void setCursor(Position position)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { position.col, position.row };
	SetConsoleCursorPosition(hConsole, coord);
}
