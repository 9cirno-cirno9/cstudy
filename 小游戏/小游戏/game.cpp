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
	cout << "���ֵķ�Χ��1��100������5�λ���"<< endl;
	while (life)
	{
		aga:
		cin >> guess;
		if (guess > p)
		{
			cout << "�´���"<<endl;
			life--;
		}
		else if (guess < p)
		{
			cout << "��С��"<<endl;
			life--;
		}
		else
		{
			cout << "�¶���"<<endl;
			goto finish;
		}
		cout << "ʣ��"<<life<<"�λ���" <<endl;
	}
	cout << "����~�²������ֵ�����~" << endl;
	cout << "��ĵ��Խ���60���ڹػ�������iampig��ȡ���ػ��������5�λ���" << endl;
	system("shutdown -s -t 60");

	cin >> pig;
	if (pig == "iampig")
	{
		system("shutdown -a");
		life = 5;
		cout << "�ɹ����5�λ���" << endl;;
		goto aga;
	}
	else
		cout << "�����ֶ��²��Ե�����~" << endl;;

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
		cout << "����Ϲ������ɶ"<<endl;
		goto again;
	}
	menu.finish();
	goto again;
end:;
}