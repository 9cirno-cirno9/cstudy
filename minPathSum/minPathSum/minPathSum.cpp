int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    int m = gridSize, n = *gridColSize;
    int dp[m][n];
    int sum = 0;
    for (int p = 0;p <= m - 1;p++)
    {
        sum += grid[p][0];
        dp[p][0] = sum;
    }
    sum = 0;
    for (int q = 0;q <= n - 1;q++)
    {
        sum += grid[0][q];
        dp[0][q] = sum;
    }
    for (int z = 1;z <= m - 1;z++)
        for (int x = 1;x <= n - 1;x++)
        {
            if (dp[z - 1][x] > dp[z][x - 1])
                dp[z][x] = dp[z][x - 1] + grid[z][x];
            else
                dp[z][x] = dp[z - 1][x] + grid[z][x];
        }
    return dp[m - 1][n - 1];
}