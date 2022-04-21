#include "USACO Cow Hopscotch.h"
void usacohopscotchrun()
{
    int row, column;
    long long dp[16][16] = { 0 };
    FILE* input = fopen("hopscotch.in", "r");
    FILE* output = fopen("hopscotch.out", "w");
    fscanf(input, "%d%d%*d", &row, &column);
    char grid[16][16] = { '\0' };
    for (int i = 0; i < row; i++)
    {
        fscanf(input, "%s", grid[i]);
    }
    fclose(input);
    dp[0][0] = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            for (int k = 1; i + k < row; k++)
            {
                for (int l = 1; j + l < column; l++)
                {
                    if (grid[i][j] != grid[i + k][j + l])
                    {
                        dp[i + k][j + l] += dp[i][j];
                    }
                }
            }
        }
    }
    if (row > 0 && column > 0)
    {
        fprintf(output, "%lld", dp[row - 1][column - 1]);
    }
    fclose(output);
}