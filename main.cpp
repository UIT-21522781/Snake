#include <iostream>
using namespace std;

#include <vector>
#include <windows.h>
#include <conio.h>
#include <cstring>
#include <time.h>
#include <random>

#define WIDTH 40
#define HEIGHT 20
#define BODY 'O'
#define APPLE '*'

enum class Direction
{
	up,
	right,
	down,
	left
};
struct Point
{
	int x;
	int y;
};

#pragma region GlobalVariable

vector<Point> snake = {
	Point{ WIDTH / 2 + 2, HEIGHT / 2 },
	Point{ WIDTH / 2 + 1, HEIGHT / 2 },
	Point{ WIDTH / 2, HEIGHT / 2 },
	Point{ WIDTH / 2 - 1, HEIGHT / 2 },
	Point{ WIDTH / 2 - 2, HEIGHT / 2 }
};
Direction direction = Direction::right;
Point apple;
int score = 0;
int speed = 300;
Point prevTail;
#pragma endregion

#pragma region Prototype
void gotoxy(int, int);
void drawSnake();
void drawSnakePart(Point);
void ShowConsoleCursor(bool);
void move();
void drawHeadnTail();
void genApple();
bool isHitWall();
bool isBiteItself();
bool isAteApple();
void growing();
void displayScore();
void showEndMenu();
void startGame();
void resetSnake();
void showStartMenu();
void drawBox();
#pragma endregion

int main()
{
	showStartMenu();
	return 0;
}
