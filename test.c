#include"game.h"



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

void game()
{
    char board[ROW][COL];
    //初始化棋盘
    Initializeboard(board,ROW,COL);
    //打印棋盘
    Displayboard(board,ROW,COL);

}

int main()
{
    int input1 = 1;
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