#include<iostream>
#include<graphics.h>
#include<cstdlib>
using namespace std;
char mark[10]= {'0','1','2','3','4','5','6','7','8','9'};
bool choices[10]= {false,false,false,false,false,false,false,false,false,false};
int j=1,ch;
void board();
int fillMark(int x,int y,int color,int player)
{
    if (player == 1)
    {
        setcolor(color);
        circle(x,y,40);
        player = 2;
        mark[ch]='O';
        j++;
    }
    else
    {
        setcolor(color);
        line(x-30,y-30, x+30,y+30);
        line(x+30,y-30, x-30,y+30);
        player = 1;
        mark[ch]='X';
        j++;
    }
    return player;
}
int checkwin()
{
    setcolor(BLACK);
    if (mark[1] == mark[2] && mark[2] == mark[3]){
        line(90,120, 510,120);
        return 1;
    }
    else if (mark[4] == mark[5] && mark[5] == mark[6]){
        line(90,240, 510,240);
        return 1;
    }
    else if (mark[7] == mark[8] && mark[8] == mark[9]){
        line(90,360, 510,360);
        return 1;
    }
    else if (mark[1] == mark[4] && mark[4] == mark[7]){
        line(180,50, 180,450);
        return 1;
    }
    else if (mark[2] == mark[5] && mark[5] == mark[8]){
        line(300,50, 300,450);
        return 1;
    }
    else if (mark[3] == mark[6] && mark[6] == mark[9]){
        line(420,50, 420, 450);
        return 1;
    }
    else if (mark[1] == mark[5] && mark[5] == mark[9]){
        line(90,30, 510,450);
        return 1;
    }
    else if (mark[3] == mark[5] && mark[5] == mark[7]){
        line(510,30, 90, 450);
        return 1;
    }
    else if (mark[1] != '1' && mark[2] != '2' && mark[3] != '3'
             && mark[4] != '4' && mark[5] != '5' && mark[6] != '6'
             && mark[7] != '7' && mark[8] != '8' && mark[9] != '9')
        return 0;
    else
        return -1;
}

int main()
{
    int i=1,gd=DETECT,gm;
    initwindow(640, 480, "Tic Tac Toe Game");
    int player = 1,a=-1;
    system("MODE CON COLS=90 LINES=30");

    board();

    do
    {
        cout<<"\n Player " << player << ", Enter a number:  ";
        cin>>ch;
        if(choices[ch]==false)
        {
            choices[ch]=true;
            switch(ch)
            {
            case 1:
                player = fillMark(180,120,YELLOW, player);
                break;
            case 2:
                player = fillMark(300,120,CYAN,player);
                break;
            case 3:
                player = fillMark(420,120,YELLOW,player);
                break;
            case 4:
                player = fillMark(180,240,CYAN, player);
                break;
            case 5:
                player = fillMark(300,240,YELLOW, player);
                break;
            case 6:
                player = fillMark(420,240,CYAN, player);
                break;
            case 7:
                player = fillMark(180,360,YELLOW, player);
                break;
            case 8:
                player = fillMark(300,360,CYAN, player);
                break;
            case 9:
                player = fillMark(420,360,YELLOW, player);
                break;
            default:
                cout<<"Please Enter Number Between 1-9"<<endl;
            }
            if(i>=5)
            {
                a=checkwin();
                if(a==1)
                {
                    player = player==1?2:1;
                    cout<<"\n Hurray!!! Player "<<player<<" Won \n ";
                    system("pause");
                    return 0;

                }
                else if (a==0){
                    cout<<"\n Game Draw";
                    system("pause");
                    return 0;
                }

            }
            i++;
        }
        else
        {
            cout<<"\n You have already filled this Box ---->"<<endl;
        }
    }
    while(a==-1);
    getch();
    closegraph();
    return 0;
}

void board()
{
    settextstyle(10,0,4);
    readimagefile("background2.jpg", 0,0,640, 480);
    Sleep(5000);
    clearviewport();
    readimagefile("DSC LOGO.jpg", 0,0,640, 480);
    Sleep(5000);
    clearviewport();
    readimagefile("Capture.jpg", 0,0,640, 480);
    Sleep(5000);
    clearviewport();
    outtextxy(180,20," TIC TAC TOE ");
    line(120,60,480,60); //border
    line(120,420,480,420); //border
    line(120,60,120,420); //border
    line(480,60,480,420); //border
    line(120,180,480,180); //horizontal 1
    line(120,300,480,300); //horizontal 2
    line(240,60,240,420); //vertical 1
    line(360,60,360,420); //vertical 2


    setfillstyle(SOLID_FILL,CYAN);
    floodfill(121,61, WHITE);
    floodfill(361,61, WHITE);
    floodfill(121,301, WHITE);
    floodfill(361,301, WHITE);
    floodfill(241,181, WHITE);


    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(241,61, WHITE);
    floodfill(121,181, WHITE);
    floodfill(361,181, WHITE);
    floodfill(241,301, WHITE);

}
