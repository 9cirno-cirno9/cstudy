char* longestPalindrome(char* s)
{
    int maxstart = 0;
    int maxlen = 0;
    int left, right;
    int g = strlen(s);
    if (g > 1)
    {
        for (int i = 1;i < g;i++)
        {
            left = right = i;
            while (left > 0 && s[left] == s[left - 1])
                left--;
            while (right < g - 1 && s[right] == s[right + 1])
                right++;
            while (left > 0 && right < g - 1 && s[left - 1] == s[right + 1])
            {
                left--;
                right++;
            }
            if (right - left + 1 > maxlen)
            {
                maxlen = right - left + 1;
                maxstart = left;
            }
        }
        char* w = (char*)malloc((maxlen + 1) * sizeof(char));
        strncpy(w, maxstart + s, maxlen);
        w[maxlen] = '\0';
        return w;
    }
    else
        return s;
}
//tt