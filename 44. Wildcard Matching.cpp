class Solution
{
public:
    bool isMatch(string str, string pat)
    {

        int m = str.size();
        int n = pat.size();

        if (n == 0 && m == 0)
            return true;
        if (m == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (pat[i] != '*')
                    return false;
            }
            return true;
        }

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int j = 0; j < n; j++)
        {
            if (pat[j] == '*')
                dp[0][j + 1] = true;
            else
                break;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pat[j] == '*')
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j];

                else
                {
                    if (pat[j] == str[i] || pat[j] == '?')
                        dp[i + 1][j + 1] = dp[i][j];
                    else
                        dp[i + 1][j + 1] = false;
                }
            }
        }
        return dp[m][n];
    }
};