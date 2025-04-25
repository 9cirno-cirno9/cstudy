#include "menu.h"
using namespace std;
void menu::start()
{
	cout << "******************" << endl;
	cout << "*      game      *" << endl;
	cout << "*     1.play     *" << endl;
	cout << "*                *" << endl;
	cout << "*     2.exit     *" << endl;
	cout << "*                *" << endl;
	cout << "******************" << endl;
	cin >> m;
}
void menu::finish()
{
	cout << "******************" << endl;
	cout << "*    game end    *" << endl;
	cout << "*                *" << endl;
	cout << "*press any key to*" << endl;
	cout << "*exit to the menu*" << endl;
	cout << "*                *" << endl;
	cout << "******************" << endl;
	getchar();
	getchar();
}