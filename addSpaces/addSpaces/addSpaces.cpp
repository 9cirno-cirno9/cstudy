char* addSpaces(char* s, int* spaces, int spacesSize) 
{
    int q = strlen(s) + spacesSize;
    char* p = (char*)malloc(q + 1);
    int f = 0;
    int y, a;
    for (y = 0, a = 0;y < q;y++, a++)
    {
        if (f <= spacesSize - 1 && a == spaces[f])
        {
            f++;
            p[y] = ' ';
            y++;
        }
        p[y] = s[a];
    }
    p[y] = '\0';
    return p;
    free(p);
}