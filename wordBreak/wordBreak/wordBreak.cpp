class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int x = s.length();
        int y = wordDict.size();
        bool* dp = new bool[x + 1]();
        dp[0] = true;
        string s1;
        for (int i = 0;i <= x;i++)
            for (int j = i;j <= x;j++)
            {
                if (dp[i])
                {
                    s1 = s.substr(i, j - i);
                    for (int r = 0;r < y;r++)
                    {
                        if (s1 == wordDict[r])
                            dp[j] = true;
                    }
                }
            }
        return dp[x];
        delete[]dp;
    }
};

//dp[i]Îªtrue,s[i,i+1,,,,,j)ÔÚworddictzhong,dp[j]Îªtrue
