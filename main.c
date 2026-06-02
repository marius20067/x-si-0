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
    int verificaCastigator()
{

    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return 1;
    if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return 1;
    if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return 1;

    if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return 1;
    if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return 1;
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return 1;


    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    int celuleLibere = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != '0')
            {
                celuleLibere++;
            }
        }
    }

    if (celuleLibere == 0)
        return 0;

    return -1;
}

 int main()
{
    int row, column, move, gameStatus;
    int player;


    int scorJucator1 = 0;
    int scorJucator2 = 0;
    int streakJucator1 = 0;
    int streakJucator2 = 0;
    char joacaDinNou = 'y';


    while (joacaDinNou == 'y' || joacaDinNou == 'Y')
    {
        player = 1;
        gameStatus = -1;

        board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3';
        board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6';
        board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9';

        while (gameStatus == -1)
        {
            drawBoard();

            player = (player % 2) ? 1 : 2;
            printf("Player %d move: ", player);
            scanf("%d", &move);

            row = (move - 1) / 3;
            column = (move - 1) % 3;


            if (board[row][column] != 'X' && board[row][column] != '0')
            {
                if (player == 1)
                    board[row][column] = 'X';
                else
                    board[row][column] = '0';
            }
            else
            {
                printf("Celula este deja ocupata\n");
                player--;
            }

            gameStatus=verificaCastigator();
            player++;
        }


        drawBoard();

        if (gameStatus == 1)
        {

            if (player == 2)
            {
                scorJucator1++;
                streakJucator1++;
                streakJucator2 = 0;
                printf("\n>>> Jucatorul 1 a castigat runda! <<<\n");
            }
            else
            {
                scorJucator2++;
                streakJucator2++;
                streakJucator1 = 0;
                printf("\n>>> Jucatorul 2 a castigat runda! <<<\n");
            }
        }
        else
        {
            printf("\n>>> Egalitate! <<<\n");
            streakJucator1 = 0;
            streakJucator2 = 0;
        }

        printf("\n=== STATISTICI ===\n");
        printf("Scor general: Jucator 1 [%d] - [%d] Jucator 2\n", scorJucator1, scorJucator2);
        printf("Win Streak:   Jucator 1 (%d) | Jucator 2 (%d)\n", streakJucator1, streakJucator2);
        printf("==================\n\n");


        printf("Vreti sa jucati din nou? (y/n): ");
        scanf(" %c", &joacaDinNou);
    }

    return 0;
}


