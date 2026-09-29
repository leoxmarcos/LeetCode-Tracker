class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Valid parentheses string must have even length
        if ((m + n - 1) % 2 == 1)
            return false;

        // dp[i][j][balance]
        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(
                n,
                vector<bool>(m + n, false)
            )
        );

        // Starting cell must be '('
        if (grid[0][0] == ')')
            return false;

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                for (int balance = 0; balance <= m + n; balance++) {

                    if (dp[i][j][balance] == false)
                        continue;

                    // Move DOWN
                    if (i + 1 < m) {

                        int newBalance = balance;

                        if (grid[i + 1][j] == '(')
                            newBalance++;
                        else
                            newBalance--;

                        if (newBalance >= 0)
                            dp[i + 1][j][newBalance] = true;
                    }

                    // Move RIGHT
                    if (j + 1 < n) {

                        int newBalance = balance;

                        if (grid[i][j + 1] == '(')
                            newBalance++;
                        else
                            newBalance--;

                        if (newBalance >= 0)
                            dp[i][j + 1][newBalance] = true;
                    }
                }
            }
        }

        // Need balance = 0 at destination
        return dp[m - 1][n - 1][0];
    }
};