bool isPalindrome(int x) {
    int a[50], c = 0, d = 0, num = 0;
    if (x < 0)
    {
        return false;
    }
    else if (x == 0)
    {
        return true;
    }
    else
    {
        while (x != 0)
        {
            a[c] = x % 10;
            x = x / 10;
            c++;
        }
        for (c = c - 1;c == d || c == d + 1;c--, d++)
        {
            if (a[d] != a[c])
                num = 1;

        }
        if (num == 1)
            return false;
        else
            return true;

    }

}