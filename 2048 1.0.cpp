#include<iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
#include<string>
#include<windows.h>

using namespace std;

int boardgame[4][4]={0};
bool checkreplay=false;
void loichao()
{
    cout<<"an phim bat ki de tiep tuc";
    getch();
}
void vegame()
{
  //  return 0;
}
void startgame()
{
    system("cls");
    vegame();
    // khoi tao bang game ban dau bang 0
    srand(time(NULL));
	int newTile[4];
	newTile[0] = rand() % 4;
	newTile[1] = rand() % 4;

	do {
		newTile[2] = rand() % 4;
		newTile[3] = rand() % 4;
	} while (newTile[0] == newTile[2] || newTile[1] == newTile[3]);

	// T?o 2 giá tr? d?u
	boardgame[newTile[0]][newTile[1]] = 2;
	boardgame[newTile[2]][newTile[3]] = 2;
}
void gameover()
{
    system("cls");
    cout<< "gameover";

}
void showgame()
{

}
int main()
{
    loichao();
    startgame();
    return 0;
}
