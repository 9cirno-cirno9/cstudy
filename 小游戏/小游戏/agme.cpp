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
	cout << "���ֵķ�Χ��1��100������5�λ���" << endl;
	while (life)
	{
	aga:
		cin >> guess;
		if (guess > p)
		{
			cout << "�´���" << endl;
			life--;
		}
		else if (guess < p)
		{
			cout << "��С��" << endl;
			life--;
		}
		else
		{
			cout << "�¶���" << endl;
			goto finish;
		}
		cout << "ʣ��" << life << "�λ���" << endl;
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
	cout << "*    ѡ���Ѷ�    *" << endl;
	cout << "*   1.9*9 20��   *" << endl;
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
	while (count)//����
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
		cout << "�����������꣬��ʽ���磺 1 2" << endl;
		cin >> a >> b;
		if (a < 1 || a>9 || b < 1 || b>9)
		{
			cout << "���������û��ô��" << endl;
			goto sao;
		}
		if (lei99[a][b] == '1')
		{
			cout << "���㣬������" << endl;;
			goto end;
		}
		else//��������
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
	cout << "ɨ�׳ɹ�" << endl;


end:;
}