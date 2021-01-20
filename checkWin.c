#include "gomoku.h"

int checkWin(int x, int y, char gomoku[N][N], char flagWin)
{
    int i, j, cou1 = 0, cou2 = 0;
    // checking vertical winning
    for (int i = y + 1; i < N; i++)
    {
        if (gomoku[x][i] == flagWin)
            cou1++;
        else
            break;
    }
    for (i = y - 1; i > 0; i--)
    {
        if (gomoku[x][i] == flagWin)
            cou1++;
        else
            break;
    }
    // if there is already 4 straight chess
    if (cou1 >= 4)
        return 1;
    // initializing counter
    cou1 = 0;

    // checking horizontal winning
    for (i = x + 1; i < N; i++)
    {
        if (gomoku[i][y] == flagWin)
            cou1++;
        else
            break;
    }
    for (i = x - 1; i > 0; i--)
    {
        if (gomoku[i][y] == flagWin)
            cou1++;
        else
            break;
    }
    if (cou1 >= 4)
        return 1;
    cou1 = 0;

    // checking lower left to upper right or vice versa winning
    for (i = x + 1, j = y + 1; i < N, y < N; i++, j++)
    {
        if (gomoku[i][j] == flagWin)
            cou1++;
        else
            break;
    }
    for (i = x - 1, j = y - 1; i > 0, j > 0; i--, j--)
    {
        if (gomoku[i][j] == flagWin)
            cou1++;
        else
            break;
    }
    if (cou1 >= 4)
        return 1;
    cou1 = 0;

    // checking upper left to lower right or vice versa winning
    for (i = x - 1, j = y + 1; i > 0, j < N; i--, j++)
    {
        if (gomoku[i][j] == flagWin)
            cou1++;

        else
            break;
    }
    for (i = x + 1, j = y - 1; i<N, j> 0; i++, j--)
    {
        if (gomoku[i][j] == flagWin)
            cou1++;
        else
            break;
    }
    if (cou1 >= 4)
        return 1;
    return 0;
}