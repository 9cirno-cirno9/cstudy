int fib(int n)
{
    int a = 1, b = 1, c = 0;
    if (n == 1)
        return 1;
    else if (n == 2)
        return 1;
    else
    {
        for (int r = 1;r <= n - 2;r++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}