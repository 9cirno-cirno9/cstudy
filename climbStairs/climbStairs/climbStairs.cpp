int climbStairs(int n)
{
    int* d = (int*)malloc((n + 2) * sizeof(int));
    d[0] = 1;
    d[1] = 2;
    for (int y = 2;y <= n - 1;y++)
    {
        d[y] = d[y - 1] + d[y - 2];
    }
    return d[n - 1];
    free(d);
}
