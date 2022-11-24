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
