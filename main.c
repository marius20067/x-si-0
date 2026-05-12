#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

char board[3][3] = {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'}
};
void drawBoard(){
    for(int i=0;i<3;i++)
        {
            printf("%c | %c | %c\n" ,board[i][0],board[i][1],board[i][2]);
            if(i!=2)
            {
                printf("---|-----|---\n");
            }
        }
    }
int checkwin(){

        for(int i=0;i<3;i++)
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return 1;
        }
    for(int i=0;i<3;i++)
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
    {
        return 1;
    }
   if (board[0][0] == board[1][1] && board [1][1] == board[2][2])
   {
       return 1;
   }
   if (board[2][0] == board[1][1] && board [1][1] == board[0][2])
    {
       return 1;
    }
    int count = 0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            {if(board[i][j]!='X' && board[i][j]!='0')
                count++;

            }
            if(count == 0)
                return 2;
            return 0;
    }

int main()
{   int row,column,move,gameStatus;
    int player=1;
    while(1){
        system("cls");
        drawBoard();
        player=(player %2)? 1: 2;
        printf("Player %d move: ",player);
        scanf("%d",&move);
        row = (move - 1)/3;
        column = (move - 1)%3;
        if (board[row][column] != 'X' && board[row][column] !='0')
            {if(player == 1)
                board[row][column] = 'X';

            else
               {

               board[row][column] = '0';
               }
               }
            else
            {


                printf("Celula este deja ocupata\n");
                player--;
            }
               drawBoard();
               gameStatus=checkwin();
            if(gameStatus == 1)
            {
                printf("Player %d win",player);
                break;
            }
            if(gameStatus == 2)
            {
                printf("Egal");
                break;
            }
            player++;
            }


return 0;
}
