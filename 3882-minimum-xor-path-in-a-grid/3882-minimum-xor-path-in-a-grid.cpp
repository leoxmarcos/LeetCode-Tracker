class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> dp(n, vector<bool>(1024, false));

        for (int i = 0; i < m; i++) {
            vector<vector<bool>> next(n, vector<bool>(1024, false));

            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    next[j][grid[i][j]] = true;
                    continue;
                }

                for (int x = 0; x < 1024; x++) {
                    if (i > 0 && dp[j][x]) {
                        next[j][x ^ grid[i][j]] = true;
                    }

                    if (j > 0 && next[j - 1][x]) {
                        next[j][x ^ grid[i][j]] = true;
                    }
                }
            }

            dp = next;
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x])
                return x;
        }

        return -1;
    }
};