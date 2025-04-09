int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
    int maxaa = 0;
    int dp[matrixSize][*matrixColSize];
    for (int q = 0;q < matrixSize;q++)
    {
        if (matrix[q][0] == '0')
            dp[q][0] = 0;
        else
            dp[q][0] = 1;
        maxaa = max(maxaa, dp[q][0]);
    }
    for (int p = 0;p < *matrixColSize;p++)
    {
        if (matrix[0][p] == '0')
            dp[0][p] = 0;
        else
            dp[0][p] = 1;
        maxaa = max(maxaa, dp[0][p]);
    }
    for (int m = 1;m < matrixSize;m++)
        for (int n = 1;n < *matrixColSize;n++)
        {
            if (matrix[m][n] == '0')
                dp[m][n] = 0;
            else
                dp[m][n] = min(min(dp[m][n - 1], dp[m - 1][n]), dp[m - 1][n - 1]) + 1;
            maxaa = max(maxaa, dp[m][n]);
        }
    return maxaa * maxaa;
}