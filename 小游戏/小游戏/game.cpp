using namespace std;
#include "agme.h"
#include "menu.h"
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
		case 2:
			game.saolei();
			break;
		}
		break;
	case 2:
		goto end;
	default:
		cout << "ÄãÔÚÏ¹¼¸°ÑÊäÉ¶"<<endl;
		goto again;
	}
	menu.finish();
	goto again;
end:;
}