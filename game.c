#include"game.h"

/*菜单*/
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
        }
        if(i<row-1)
        {
            for(j=0;j<col;j++)
            {
                printf("---");
            }
            if(j<col-1)
            {
                printf("|");
            }
        }
    }
}