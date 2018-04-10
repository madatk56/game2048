#include<iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
#include<string>
#include<windows.h>

using namespace std;
class game
{
public :
    int score,max,win,plus;
    bool checkreplay;
//    game: checkreplay(false);
//    game(): score(0),plus(0),win(2048);
    void vegame();
    void startgame();
    void loichao();
    void showgame();
    bool checkgameover();
    bool checkzero();
    void creatcheck();
    bool checkmove();
    void addboard();
    void gameover();
    void goup();
    void godown();
    void turnleft();
    void turnright();
    void highscore();
    void play_game();

};
game exec;
int boardgame[4][4]={0};
void game::loichao()
{
    cout<<"an phim bat ki de tiep tuc";
    getch();
}
void game::vegame()
{
  //  return 0;
}
void game::startgame()
{   for(int i=0;i<5;i++)
    for(int j=0;j<5;j++) boardgame[i][j]=0;
    exec.score=0;
    system("cls");
   // vegame();
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
void game::gameover()
{
    system("cls");
    cout<< "gameover";

}
void game::showgame()
{    system("cls");
    for(int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
            cout<< boardgame[i][j]<<"      ";
            cout<<"\n";

    }
}
void game:: goup()
{
    // Ðua các giá lên trên cùng

	for (int j = 0; j < 4; j++) {
		int t = 0;
		for (int i = 0; i < 4; i++) {
			if (boardgame[i][j] != 0) {
				boardgame[t][j] = boardgame[i][j];
				t++;
			}
		}
		for (int i = t; i < 4; i++) boardgame[i][j] = 0;
	}


	// G?p các giá tr? trùng nhau

	for (int j = 0; j < 4; j++) {
		int t = 0;
		for (int i = 0; i < 4; i++) {
			if (boardgame != 0) {
				if (boardgame[i][j] == boardgame[i + 1][j]) {
					boardgame[t][j] = 2 * boardgame[i][j];
				//	gameScore += boardgame[t][j];
					t++;
					i++;
				}
				else {
					boardgame[t][j] = boardgame[i][j];
					t++;
				}
			}
		}
		for (int i = t; i < 4; i++) boardgame[i][j] = 0;
	}


}
void game:: godown()
{
     int t;
    //day het cac so xuong
        for (int j=0;j<4;j++)
        {
            t=3;
            for(int i=3;i>=0;i--)
            if (boardgame[i][j]!=0)
            {
                boardgame[t][j]=boardgame[i][j];
                t--;
            }
        for(int i=t;i>=0;i--) boardgame[i][j]=0;
        }
    // cac si co gia tri bang nhau thi duoc cong lai
    for (int j = 0; j < 4; j++)
    {
        for (int i=3;i>0;i--)
            if (boardgame[i][j]==boardgame[i-1][j])
        {
            boardgame[i][j]+=boardgame[i][j];
            for(int run=i-1;run>0;run--)
            {
                boardgame[run][j]=boardgame[run-1][j];
            }
            boardgame[0][j]=0;
        }
    }

}
void game:: turnleft()
{
   for (int i = 0; i < 4; i++) {
		int t = 0;
		for (int j = 0; j < 4; j++) {
			if (boardgame[i][j] != 0) {
				boardgame[i][t] = boardgame[i][j];
				t++;
			}
		}
		for (int j = t; j < 4; j++) boardgame[i][j] = 0;
	}

	// G?p các giá tr? trùng nhau

	for (int i = 0; i < 4; i++) {
		int t = 0;
		for (int j = 0; j < 4; j++) {
			if (boardgame[i][j] != 0) {
				if (boardgame[i][j] == boardgame[i][j + 1]) {
					boardgame[i][t] = 2 * boardgame[i][j];
					//gameScore += boardGame[i][t];
					j++;
					t++;
				}
				else {
					boardgame[i][t] = boardgame[i][j];
					t++;
				}
			}
		}
		for (int j = t; j < 4; j++) boardgame[i][j] = 0;
	}
}
void game:: turnright()
{
    int t;
    for(int i=0;i<4;i++)
    {
        t=3;
        for(int j=3;j>=0;j--)
            if( boardgame[i][j]!=0)
        {
            boardgame[i][t]=boardgame[i][j];
            t--;
        }
    for(int j=0;j<=t;j++)
            boardgame[i][j]=0;

    }
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>0;j--)
        {
            if (boardgame[i][j]==boardgame[i][j-1])
            {
                boardgame[i][j]+=boardgame[i][j];
                for(int run=j-1;run>0;run--)
                    boardgame[i][run]=boardgame[i][run-1];
                boardgame[i][0]=0;
            }
        }
    }
}
void  play_game()
{
    char control;
   while(true)
   {
      if(exec.checkreplay==true) {exec.startgame();exec.checkreplay=false;}
      exec.showgame();
    if(exec.checkgameover()==true) exec.gameover();
    exec.creatcheck();
       control=getch();
    if (control=='w') exec.goup();
    else if(control=='s') exec.godown();
    else if (control=='a') exec.turnleft();
    else if (control=='d') exec.turnright();
    else if (control=='r') exec.checkreplay=true;
    /*switch(control
    {

        case 'w': exec.goup(); break;//continue;
        case 's': exec.godown(); break;
        case 'd': exec.turnright(); break;
        case 'a': exec.turnleft(); break;

    }*/
    if (exec.checkmove()==false) exec.addboard();
   // exec.showgame();
   }
   }
bool game::checkzero()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {if(boardgame[i][j]==0 ) return true;}
    return false;
}
void game:: addboard()
{
    if (checkzero()==false) return;

    int x,y;
    srand(time(NULL));
    do
    {
        x=rand()%4;
        y=rand()%4;
    } while (boardgame[x][y]!=0);
    int xacxuat;
    xacxuat=rand()%100;
    if(xacxuat>90) boardgame[x][y]=4; else boardgame[x][y]=2;

}
int boardcheck[4][4];
void game::creatcheck()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
    {
        boardcheck[i][j]=boardgame[i][j];
    }
}
bool game::checkmove()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
    {
        if(boardcheck[i][j]!=boardgame[i][j]) return false;
    }
    return true;
}
bool game::checkgameover()
{
    if(checkzero()==true) return false;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        if(boardgame[i][j]==boardgame[i][j+1]||boardgame[i][j]==boardgame[i+1][j]) return false;
    return true;
}
int main()
{
    exec.checkreplay=false;
    exec.loichao();
    exec.startgame();
    play_game();

    return 0;
}
