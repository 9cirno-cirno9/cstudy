int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize)
{
    int m = matrixSize;
    int n = matrixSize;
    int dp[m][n];
    int minaa;
    for (int q = 0;q <= m - 1;q++)
    {
        dp[0][q] = matrix[0][q];
    }
    for (int x = 1;x <= m - 1;x++)
        for (int y = 0;y <= m - 1;y++)
        {
            if (y == 0)
                dp[x][0] = min(dp[x - 1][0], dp[x - 1][1]) + matrix[x][0];
            else if (y == m - 1)
                dp[x][m - 1] = min(dp[x - 1][m - 2], dp[x - 1][m - 1]) + matrix[x][m - 1];
            else
                dp[x][y] = min(dp[x - 1][y], min(dp[x - 1][y - 1], dp[x - 1][y + 1])) + matrix[x][y];
        }
    minaa = dp[m - 1][0];
    for (int a = 1;a <= m - 1;a++)
    {
        minaa = min(minaa, dp[m - 1][a]);
    }
    return minaa;
}
//text