class Solution
{
public:
    bool isMatch(string str, string sub)
    {

        int n = sub.size(), m = str.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n; i++)
        {
            if (sub[i - 1] == '*')
                dp[i][0] = dp[i - 2][0];
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (sub[i - 1] == '.' || str[j - 1] == sub[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (sub[i - 1] == '*')
                {
                    if (sub[i - 2] == '.' || sub[i - 2] == str[j - 1])
                        dp[i][j] = (dp[i - 2][j] || dp[i][j - 1]);
                    else
                        dp[i][j] = dp[i - 2][j];
                }
            }
        }
        return dp[n][m];
    }
};