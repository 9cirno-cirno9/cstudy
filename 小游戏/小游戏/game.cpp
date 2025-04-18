#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
class menu
{
public:
	void start();
	void finish();
	int m;
};
class game
{
public:
	void gamemenu();
	void guessnum();
	int n;
};
void menu::start()
{
	cout<<"******************"<<endl;
	cout<<"*      game      *"<<endl;
	cout<<"*     1.play     *"<<endl;
	cout<<"*                *"<<endl;
	cout<<"*     2.exit     *"<<endl;
	cout<<"*                *"<<endl;
	cout<<"******************"<<endl;
	cin >> m;
}
void menu::finish()
{
	int a;
	cout << "******************" << endl;
	cout << "*    game end    *" << endl;
	cout << "*                *" << endl;
	cout << "*press any key to*" << endl;
	cout << "*exit to the menu*" << endl;
	cout << "*                *" << endl;
	cout << "******************" << endl;
	cin >> a;
}
void game::gamemenu()
{
	cout << "******************" << endl;
	cout << "*                *" << endl;
	cout << "*   1.guessnum   *" << endl;
	cout << "*                *" << endl;
	cout << "*                *" << endl;
	cout << "*                *" << endl;
	cout << "******************" << endl;
	cin >> n;

}
void game::guessnum()
{
	string pig;
	int life = 5;
	int guess;
	int p = rand() % 100 + 1;
	cout << "数字的范围在1到100，你有5次机会"<< endl;
	while (life)
	{
		aga:
		cin >> guess;
		if (guess > p)
		{
			cout << "猜大了"<<endl;
			life--;
		}
		else if (guess < p)
		{
			cout << "猜小了"<<endl;
			life--;
		}
		else
		{
			cout << "猜对了"<<endl;
			goto finish;
		}
		cout << "剩余"<<life<<"次机会" <<endl;
	}
	cout << "杂鱼~猜不对数字的杂鱼~" << endl;
	cout << "你的电脑将在60秒内关机，输入iampig，取消关机，并获得5次机会" << endl;
	system("shutdown -s -t 60");

	cin >> pig;
	if (pig == "iampig")
	{
		system("shutdown -a");
		life = 5;
		cout << "成功获得5次机会" << endl;;
		goto aga;
	}
	else
		cout << "猜数字都猜不对的杂鱼~" << endl;;

finish:;
	
}

int main()
{
	srand((unsigned int)time(NULL));
	menu menu;
	game game;
	again:
	menu.start();
	switch (menu.m)
	{
	case 1:
		game.gamemenu();
		switch (game.n)
		{
		case 1:
			game.guessnum();
			break;
		}
		break;
	case 2:
		goto end;
	default:
		cout << "你在瞎几把输啥"<<endl;
		goto again;
	}
	menu.finish();
	goto again;
end:;
}