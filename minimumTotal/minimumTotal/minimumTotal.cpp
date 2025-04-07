int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
    int m = triangleSize;
    int dp[m][m];
    int x, y;
    int min;
    int sum1 = 0, sum2 = 0;
    for (int q = 0;q <= m - 1;q++)
    {
        sum1 += triangle[q][0];
        dp[q][0] = sum1;
        sum2 += triangle[q][q];
        dp[q][q] = sum2;
    }
    for (x = 2;x <= m - 1;x++)
        for (y = 1;y <= x - 1;y++)
        {
            if (dp[x - 1][y] < dp[x - 1][y - 1])
                dp[x][y] = dp[x - 1][y] + triangle[x][y];
            else
                dp[x][y] = dp[x - 1][y - 1] + triangle[x][y];
        }
    min = dp[m - 1][0];
    for (int z = 1;z <= m - 1;z++)
    {
        if (dp[m - 1][z] < min)
            min = dp[m - 1][z];
    }
    return min;
}
