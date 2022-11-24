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