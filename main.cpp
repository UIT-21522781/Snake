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

void drawBox()
{
	for (size_t i = 0; i < WIDTH; i++)
		cout << '=';
	gotoxy(0, HEIGHT);
	for (size_t i = 0; i < WIDTH; i++)
		cout << '=';
	for (size_t i = 1; i < HEIGHT; i++)
	{
		gotoxy(0, i);
		cout << '|';
	}
	for (size_t i = 1; i < HEIGHT; i++)
	{
		gotoxy(WIDTH, i);
		cout << '|';
	}
}
int main()
{
	showStartMenu();
	return 0;
}

void drawSnake()
{
	for (size_t i = 0; i < snake.size(); i++)
		drawSnakePart(snake[i]);
}
void drawSnakePart(Point p)
{
	gotoxy(p.x, p.y);
	cout << BODY;
}
void drawHeadnTail()
{
	gotoxy(snake[0].x, snake[0].y);
	cout << BODY;
	gotoxy(prevTail.x, prevTail.y);
	cout << ' ';
}
void growing()
{
	snake.push_back(prevTail);
}
void resetSnake()
{
	score = 0;
	direction = Direction::right;
	snake = {
		Point{ WIDTH / 2 + 2, HEIGHT / 2 },
		Point{ WIDTH / 2 + 1, HEIGHT / 2 },
		Point{ WIDTH / 2, HEIGHT / 2 },
		Point{ WIDTH / 2 - 1, HEIGHT / 2 },
		Point{ WIDTH / 2 - 2, HEIGHT / 2 }
	};
}

void move()
{
	prevTail = snake.back();
	for (size_t i = snake.size() - 1; i > 0; i--)
		snake[i] = snake[i - 1];
	if (direction == Direction::up)
		snake[0].y -= 1;
	else if (direction == Direction::down)
		snake[0].y += 1;
	else if (direction == Direction::left)
		snake[0].x -= 1;
	else if (direction == Direction::right)
		snake[0].x += 1;
}
void showStartMenu()
{
	int option=0;
	while (option != 1 && option != 2)
	{
		system("cls");
		cout << "Chao mung ban da den voi game Ran san moi!" << endl;
		cout << "Lua chon:" << endl;
		cout << "1. Bat dau" << endl;
		cout << "2. Thoat" << endl;
		cout << "Nhap lua chon: ";
		cin >> option;
	};
	if (option == 1)
	{
		system("cls");
		int t = 0;
		while (t< 1 || t >5)
		{
			system("cls");
			cout << "Chon cap do (1 - 5): ";
			cin >> t;
		};
		speed = 600 - t * 100;
		system("cls");
		cout << "Meo: Trong khi choi game, ban co the nhan 'q' de thoat" << endl;
		gotoxy(0, 3);
		cout << "Ready!";
		Sleep(1000);
		for (size_t i = 3; i > 0; i--)
		{
			gotoxy(0, 3);
			cout << i << "         ";
			Sleep(1000);
		}
		gotoxy(0, 3);
		cout << "GO!";
		Sleep(1000);
		startGame();
	}
	else if (option == 2)
		exit(1);
}
void showEndMenu()
{
	gotoxy(0, 0);
	char option;
	do
	{
		system("cls");
		cout << "Ket thuc tro choi!" << endl;
		cout << "Diem so: " << score << endl;
		cout << "Ban co muon choi lai khong ([y]/[n]): ";
		cin >> option;
		option = tolower(option);
	} while (option != 'y' && option != 'n');
	if (option == 'y')
	{
		resetSnake();
		startGame();
	}
	else if (option == 'n')
		exit(1);
}

void displayScore()
{
	gotoxy(WIDTH + 5, 2);
	cout << "Diem so: " << score;
}



