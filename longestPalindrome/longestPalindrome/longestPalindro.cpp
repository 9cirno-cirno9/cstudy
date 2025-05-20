class Solution {
public:
    int longestPalindrome(string s)

    {
        vector<int> m(s.length(), 0);
        int p = 0;
        int num = 1;
        if (s.length() == 1)
            return 1;
        for (int i = 0;i < s.length();i++)
        {
            if (m[i] == 1)
                continue;
            m[i] = 1;
            for (int n = i + 1;n < s.length();n++)
            {
                if (n == s.length())
                    break;
                if (s[n] == s[i] && m[n] == 0)
                {
                    num++;
                    m[n] = 1;
                }
            }
            if (p % 2 == 0 && num % 2 != 0)
            {
                p++;
            }
            if (num % 2 == 0)
            {
                p += num;
            }
            else if (num % 2 != 0)
            {
                p += num - 1;
            }
            num = 1;
        }
        return p;
    }
};