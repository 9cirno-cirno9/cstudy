int minCostClimbingStairs(int* cost, int costSize)
{
    int a, b, c;
    a = 0;
    b = 0;
    for (int q = 0;q <= costSize - 2;q++)
    {
        c = a + cost[q];
        if (c > b + cost[q + 1])
            c = b + cost[q + 1];
        a = b;
        b = c;
    }
    return c;
}