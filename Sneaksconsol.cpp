// Sneaksconsol.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;


bool GameOver;
const int width = 50;
const int height = 20;
int x, y, frx, fry, score;
int TailX[100], TailY[100];
int nTail;
enum edirict {stop, LEFT, RIGHT, UP, DAUN};
edirict mv;

void Setup() {
	GameOver = false;
	mv = stop;
	x = width / 2 - 1 ;
	y = height / 2 - 1;
	frx = rand() % width;
	fry = rand() % height;
	score = 2;
}
void Draw() {
	system("cls");
	system("color F9");
	for (int i = 0; i < width+1; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1)
				cout << "#";
			if (i == y && j == x)
				cout << (char)2;
			else if (i == fry && j == frx)
				cout << (char)3;
			else{
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (TailX[k] == j && TailY[k] == i) {
						print = true;
						cout << (char)2;
					}
				}
				if (!print)
					cout << " ";
			}
			
		}
		cout << endl;
	}

	for (int i = 0; i < width+1; i++)
		cout << "#";
	cout << endl;
	cout << "score = " << score << endl;

}
void Imput(){

	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			mv = LEFT;
			break;
		case 'd':
			mv = RIGHT;
			break;
		case 'w':
			mv = UP;
			break;
		case 's':
			mv = DAUN;
			break;
		case 'x':
			GameOver = true;
			break;
		}
	}
}
void Logic() {

	int prx=TailX[0];
	TailX[0]=x;
	int pry = TailY[0];
	TailY[0] = y;
	int pr2X, pr2Y;
	for (int i = 1; i < nTail; i++) {
		pr2X = TailX[i];
		pr2Y = TailY[i];
		TailX[i] = prx;
		TailY[i] = pry;
		prx = pr2X;
		pry = pr2Y;
	}

	switch (mv)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DAUN:
		y++;
		break;
	
	}
	if (x > width || x < 0 || y > height || y < 0) {
		GameOver = true;
		cout << "GAME OVER!"<< endl;
		system("pause");
	}
	for (int i = 0; i < nTail; i++) {
		if (TailX[i] == x && TailY[i] == y)
			GameOver = true;
		cout << "GAME OVER!" << endl;
		system("pause");
	}
	if (x == frx && y == fry) {
		score += 1;
		frx = rand() % width;
		fry = rand() % height;
		nTail++;
	}
}

int main()
{
	Setup();
	for (int i = 0; i = !GameOver; i++) {
		Draw();
		Imput();
		Logic();
		
	}

	system("pause");
    return 0;
}

