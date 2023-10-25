#include "stdio.h"
#include "stdbool.h"
#include "assert.h"
#include "time.h"
#include "stdlib.h"
/* #include "conio.h" */

#define BOUNDARY 5
#define snake_length (BOUNDARY * BOUNDARY)

int main(void)
{
    printf("----------Welcome to the beta game of \"SNAKE THE CONQUEROR - II\"----------\n\n");
    printf("Rules of the game are\n\n");
    printf("1. You are controlling the snake in the game which is initially at the 1st position of a (%d X %d) grid.\n", BOUNDARY, BOUNDARY);
    printf("2. The snake is in static motion, and you have to control where it goes by the keys 8, 2, 4 and 6.\n");
    printf("3. By pressing\n\t8 - snake moves 1 block up, represented by \'^\'\n\t2 - snake moves 1 block down");
    printf(", represented by \'|\'\n\t4 - snake moves 1 block left, represented by \'<\'\n\t6 - snake moves 1 block right");
    printf(", represented by \'>\'\n\n4. In this game you'll be playing with a CPU!\n\t1. You will be given the chance to make the snake move 1st\n\t");
    printf("2. After your chance CPU will select the next move of the snake, making the snake to go at a place suited him\n\n");
    printf("3. And then again you will move, this will be done repeatedly\n");
    printf("5. You must defeat the CPU to win the game!\n\n");
    printf("5. In order to win the game\n\t1. You have to be the one who gets the chance to make the last move!\n\t");
    printf("2. Keep in mind that--\n\t\t");

    printf("1. The snake must avoid going out from all the boundaries!\n\t\t");
    printf("2. The snake must not bite / cross its own body or tail!\n\t\t");
    printf("3. The CPU can move to any available valid positions left for the current scenario in the grid\n\n"/*, BOUNDARY * BOUNDARY, BOUNDARY, BOUNDARY*/);

    int i, j, move, pivot = 0, turn = 0;
    char playing_area[BOUNDARY][BOUNDARY] = {0};
    bool up, down, left, right, flag;

    up = down = left = right = flag = false;
    i = j = move = 0;
    playing_area[i][j] = '*';
    srand((unsigned)time(NULL));

    printf("Visual Representation of the initial state\n\n");
    for(int i = 0; i < BOUNDARY; i++)
    { 
        for(int j = 0; j < BOUNDARY; j++)
            playing_area[i][j] == 0 ? printf(". ") : printf("%c ",playing_area[i][j]);

        printf("\n");
    }

    while(pivot < snake_length)
    {
        up = down = left = right = false;

        if(i - 1 >= 0 && playing_area[i - 1][j] == 0)
            up = true;

        if(i + 1 < BOUNDARY && playing_area[i + 1][j] == 0)
            down = true;

        if(j - 1 >= 0 && playing_area[i][j - 1] == 0)
            left = true;

        if(j + 1 < BOUNDARY && playing_area[i][j + 1] == 0)
            right = true;

        if(up + down + left + right == false)
        {
            ++pivot;
            break;
        }

        if(++turn % 2 == 0)
        {
            ++pivot;
            /// cpu turn
            int move = rand() % 4;

            switch(move)
            {
                case 0:
                        s1:
                        if(up)
                        {
                            playing_area[--i][j] = '^';
                            break;
                        }
                case 1:
                        if(down)
                        {
                            playing_area[++i][j] = '|';
                            break;
                        }
                case 2:
                        if(left)
                        {
                            playing_area[i][--j] = '<';
                            break;
                        }
                case 3:
                        if(right)
                        {
                            playing_area[i][++j] = '>';
                            break;
                        }
                        else
                            goto s1;
            }

            printf("\nPress any key to see the CPU's move\n");
            /* getch(); */
            getchar();
            getchar();
            printf("\n-------------------------------------------------------------------------------------------------\n");
            printf("\n---After CPU's turn---\n");

            for(int i = 0; i < BOUNDARY; i++)
            {
                for(int j = 0; j < BOUNDARY; j++)
                    playing_area[i][j] == 0 ? printf(". ") : printf("%c ",playing_area[i][j]);

                printf("\n");
            }

            continue;
        }

        again:
        printf("\n---Enter your move---\n");
        scanf("%d",&move);

        if(move != 2 && move != 4 && move != 6 && move != 8)
        {
            printf("You Entered the wrong move. Controls are 8, 2, 4 and 6\n");
            goto again;
        }

        ++pivot;

        switch(move)
        {
            case 8:
                    if(up)
                    {
                        playing_area[--i][j] = '^';
                        break;
                    }
                    else
                    {
                        flag = 1;
                        goto end;
                    }
            case 2:
                    if(down)
                    {
                        playing_area[++i][j] = '|';
                        break;
                    }
                    else
                    {
                        flag = 1;
                        goto end;
                    }
            case 4:
                    if(left)
                    {
                        playing_area[i][--j] = '<';
                        break;
                    }
                    else
                    {
                        flag = 1;
                        goto end;
                    }
            case 6:
                    if(right)
                    {
                        playing_area[i][++j] = '>';
                        break;
                    }
                    else
                    {
                        flag = 1;
                        goto end;
                    }
        }

        printf("\n-------------------------------------------------------------------------------------------------\n");
        printf("\n---After Your turn---\n");
        for(int i = 0; i < BOUNDARY; i++)
        {
            for(int j = 0; j < BOUNDARY; j++)
                playing_area[i][j] == 0 ? printf(". ") : printf("%c ",playing_area[i][j]);

            printf("\n");
        }
    }

    end:

    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------------------------------------\n");

    if(turn % 2 == 0 || flag)
    {
        printf("\n---------------------YOU LOSE!---------------------\n");

        if(flag)
            printf("The snake can not cross itself nor the boundaries!\n");
        else
        printf("-> There is no place left for you to move!\n-> CPU won the game!\n");

        printf("---------------BETTER LUCK NEXT TIME---------------\n");
    }

    else if(turn % 2 || pivot == snake_length)
    {
        printf("\n----------------------CONGRATULATIONS! YOU WIN------------------------\n");
        printf("\nYou eliminated the CPU by leaving no place for it to move!\n");
        printf("but can you do that again?\n");
    }

    playing_area[i][j] = '#';

    printf("\n-> * is the starting point of your snake\n-> # is the ending point of your snake\n");
    printf("\n---Your final game is---\n");

    for(int i = 0; i < BOUNDARY; i++)
    {
        printf("\n");

        for(int j = 0; j < BOUNDARY; j++)
            playing_area[i][j] == 0 ? printf(". ") : printf("%c ",playing_area[i][j]);
    }

    printf("\n\n-> Maximum length of the snake was %d\n",pivot);
    /* getch(); */
    getchar();
    getchar();
    printf("\nDEVELOPED BY -> Sanisha Prakash \n");
    return 0;
}
