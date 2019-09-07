#include <iostream>
#include <conio.h>
#include <windows.h>
#include <direct.h>
#include <time.h>

#define MAXSNAKESIZE 100

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorPosition;

void gotoxy(int x, int y) {
	cursorPosition.X = x;
	cursorPosition.Y = y;

	SetConsoleCursorPosition(console, cursorPosition);
}

class Point {
private:
	int x;
	int y;
public:
	Point() {
		x = y = 10;
	}

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void setPoint(int x, int y) {
		this->x = x;
		this->y = y;
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	void moveUp() {
		this->y--;
	}

	void moveDown() {
		this->y++;
	}

	void moveLeft() {
		this->x--;
	}

	void moveRight() {
		this->x++;
	}

	void draw() {
		gotoxy(x, y);
		cout << "*";
	}

	void erase() {
		gotoxy(x, y);
		cout << " ";
	}

	void copyPos(Point * p) {
		p->x = x;
		p->y = y;
	}

	void debug() {
		cout << "(" << x << "," << y << ")";
	}
};

class Snake {
private:
	Point * cell[MAXSNAKESIZE]; // array of points to represent snake
	int size; // current size of snake
	char dir; // current direction of snake
	Point fruit;
public:
	Snake() {
		size = 1;
		dir = 'z';
		cell[0] = new Point(20, 20); // default position

		for (int i = 1; i < MAXSNAKESIZE; i++) {
			cell[i] = NULL;
		}

		fruit.setPoint(rand() % 50, rand() % 25);
	}
	void addCell(int x, int y) {
		cell[size++] = new Point(x, y);
	}

	void TurnUp() {
		dir = 'w'; // w is control key for turning up
	}

	void TurnDown() {
		dir = 's'; // s is control key for turning down
	}

	void TurnLeft() {
		dir = 'a'; // s is control key for turning left
	}

	void TurnRight() {
		dir = 'd'; // d is control key for turning right
	}

	void Move() {
		// clear screen
		system("cls");

		// making snake body follow its head
		for (int i = size - 1; i > 0; i--) {
			cell[i - 1]->copyPos(cell[i]);
		}

		// turning snake's head
		switch (dir) {
		case 'w':
			cell[0]->moveUp();
			break;
		case 's':
			cell[0]->moveDown();
			break;
		case 'a':
			cell[0]->moveLeft();
			break;
		case 'd':
			cell[0]->moveRight();
			break;
		}

		// collision with fruit
		if (fruit.getX() == cell[0]->getX()
				&& fruit.getY() == cell[0]->getY()) {
			addCell(0, 0);

			fruit.setPoint(rand() % 50, rand() % 25);
		}

		// drawing snake
		for (int i = 0; i < size; i++) {
			cell[i]->draw();

			fruit.draw();

			debug();

			Sleep(50);
		}
	}

	void debug() {
		for (int i = 0; i < size; i++) {
			cell[i]->debug();
		}
	}
};

int main() {
	// random no generation
	srand((unsigned) time(NULL));

	// testing snake
	Snake snake;
	char op = 'l';

	do {
		if (kbhit()) {
			op = getch();
		}

		switch (op) {
		case 'w':
		case 'W':
			snake.TurnUp();
			break;
		case 's':
		case 'S':
			snake.TurnDown();
			break;
		case 'a':
		case 'A':
			snake.TurnLeft();
			break;
		case 'd':
		case 'D':
			snake.TurnRight();
			break;
		}

		snake.Move();
	} while (op != 'e');

	return 0;
}
