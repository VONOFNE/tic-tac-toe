#include <stdio.h>
#include<stdlib.h>
#include <time.h>

const int ROW = 3;
const int COL = 3;



void menu()
{
    printf("------------------\n");
    printf("------1.play------\n");
    printf("------0.exit------\n");
    printf("------------------\n");
}

void Initializeboard(char board[ROW][COL],int row,int col)
{
    int i = 0;
    int j = 0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<COL;j++)
        {
            board[i][j] = ' ';
        }
    }
}

void Displayboard(char board[ROW][COL],int row,int col)
{
    int i = 0;
    for(i=0;i<row;i++)
    {
        int j = 0;
        for(j=0;j<col;j++)
        {
            printf(" %c ",board[i][j]);
            if(j<col-1)
            {
                printf("|");
            }
            else
            {
                printf("\n");
            }
        }
        if(i<row-1)
        {
            for(j=0;j<col;j++)
            {
                printf("---");
            if(j<col-1)
            {
                printf("|");
            }
            else
            {
                printf("\n");
            }
            }
        }
    }
}

void Playermove(char board[ROW][COL],int row,int col)
{
    int x = 0;
    int y = 0;
    while(1)
    {
        printf("Please make your move>:");
        scanf("%d %d",&x,&y);
        if(board[x-1][y-1] = ' ')
        {
            if((x>0 && x <= 3) && (y>0 && y <= 3))
            {
                board[x-1][y-1] = '*';
                break;
            }
            else
            {
                printf("Wrong number,please re-enter");
            }
        }
        else
        {
            printf("Occupied");
        }
    }
}

void Computermove(char board[ROW][COL],int row,int col)
{
    printf("Computer moves>:\n");
    while(1)
    {
        int x = rand() % row;
        int y = rand() % col;
        if(board[x][y] = ' ' && board[x][y] != '*' )
        {
            board[x][y] = '#';
            break;
        }
    }    
}

char Iswin(char board[ROW][COL],int row,int col)
{
    int i = 0;
    for(i = 0;i<row;i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board [i][1] != ' ')
        {
            return board[i][1];
        }
    }
    for(i = 0;i<col;i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board [1][i] != ' ')
        {
            return board[1][i];
        }
    }
    i = 0;
    int j = 0; 
    int count  = 0;
    while(i < col - 1)
    {
        if(board[i][j] == board[i+1][j+1] && board[i][j] != ' ')
        {
            count++;
        }
        i++;
        j++;
    }
    if(count == 2)
    {
        return board[i][j];
    }
    return 'c';
}

void game()
{
    char board[ROW][COL];
    //初始化棋盘
    Initializeboard(board,ROW,COL);
    //打印棋盘
    Displayboard(board,ROW,COL);
    char ret = 'c';
    while(1)
    {
        //玩家走
        Playermove(board,ROW,COL);
        Displayboard(board,ROW,COL);
        ret = Iswin(board,ROW,COL);
        if(ret != 'c')
        {
            break;
        }
        //电脑走
        Computermove(board,ROW,COL);
        Displayboard(board,ROW,COL);
        ret = Iswin(board,ROW,COL);
        if(ret != 'c')
        {
            break;
        }
    }
}

int main()
{
    int input1 = 1;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("Please input >-");
        scanf("%d",&input1);
        switch (input1)
        {
        case 1:
        game();
            break;
        case 0:
        printf("Game Over");
            break;
        default:
        printf("Input error, please re-enter");
            break;
        }
    } while (input1);
    
    return 0;
}