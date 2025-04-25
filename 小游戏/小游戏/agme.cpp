#include <time.h>
#include <stdlib.h>
#include "agme.h"
using namespace std;
void game::gamemenu()
{
	cout << "******************" << endl;
	cout << "*                *" << endl;
	cout << "*   1.guessnum   *" << endl;
	cout << "*   2.saolei     *" << endl;
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
	cout << "数字的范围在1到100，你有5次机会" << endl;
	while (life)
	{
	aga:
		cin >> guess;
		if (guess > p)
		{
			cout << "猜大了" << endl;
			life--;
		}
		else if (guess < p)
		{
			cout << "猜小了" << endl;
			life--;
		}
		else
		{
			cout << "猜对了" << endl;
			goto finish;
		}
		cout << "剩余" << life << "次机会" << endl;
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
void game::leidisplay(vector<vector<char>> p)
{
	int n = p.size()-2;
		for (int i = 0;i < n+1;i++)
		{
			for (int j = 0;j < n+1;j++)
			{
				if (i == 0)
				{
					cout << j  << "  ";
					if (j == 0)
						cout << "    ";
				}
				else
				{
					if (j == 0)
						cout << i<<"      ";
					else
						cout << p[i ][j ] << "  ";
				}
			}
			cout << endl;
			if (i == 0)
				cout << endl<<endl;
		}

}
void game::saolei()
{
	int a;
	int hang,lie;
	int lei;
	int nolei;
	cout << "******************" << endl;
	cout << "*    选择难度    *" << endl;
	cout << "*   1.9*9 20雷   *" << endl;
	cout << "*                *" << endl;
	cout << "*                *" << endl;
	cout << "*                *" << endl;
	cout << "******************" << endl;
	cin >> a;
	if (a == 1)
	{
		hang = 9;
		lie = 9;
		lei = 20;
		nolei = 61;
	}
	vector<vector<char>> lei99(hang+2, vector<char>(lie+2, '0'));
	vector<vector<char>> open99(hang+2, vector<char>(lie+2, '*')); 
	int count = lei;
	while (count)//布雷
	{
		int x = rand() % hang + 1;
		int y = rand() % lie + 1;
		if (lei99[x][y] == '0')
		{
			lei99[x][y] = '1';
			count--;
		}		
	}
	while (nolei)
	{
		int a=0, b=0;
		leidisplay(open99);
		sao:
		cout << "输入排雷坐标，格式例如： 1 2" << endl;
		cin >> a >> b;
		if (a < 1 || a>9 || b < 1 || b>9)
		{
			cout << "你输个蛋，没那么大" << endl;
			goto sao;
		}
		if (lei99[a][b] == '1')
		{
			cout << "杂鱼，这是雷" << endl;;
			goto end;
		}
		else//算雷数量
		{
			int num=0;
			for (int i = a - 1;i <= a+1 ;i++)
			{
				for (int j = b - 1;j <= b+1 ;j++)
				{
					if (lei99[i][j] == '1')
						num++;
				}
			}
			open99[a][b] = '0' + num;
			nolei--;
		}

	}
	cout << "扫雷成功" << endl;


end:;
}