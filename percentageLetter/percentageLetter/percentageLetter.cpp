int percentageLetter(char* s, char letter)
{
    char t;
    int y = 0;
    int r = strlen(s);
    for (int p = 0;s[p] != '\0';p++)
    {
        t = s[p];
        if (t == letter)
        {
            y++;
        }
    }
    return(100 * y / r);
}
//asdasd