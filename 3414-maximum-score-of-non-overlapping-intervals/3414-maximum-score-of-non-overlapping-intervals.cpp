class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store: {left, right, weight, original index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by ending point
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1])
                return x[1] < y[1];
            return x[0] < y[0];
        });

        // p[i] = last interval before i which does not overlap
        vector<int> p(n);

        for (int i = 0; i < n; i++) {
            int low = 0, high = i - 1;
            p[i] = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                // Non-overlapping means:
                // previous right < current left
                if (a[mid][1] < a[i][0]) {
                    p[i] = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        // dp[i][k] = best answer using first i intervals
        // and selecting at most k intervals
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        // Initially all scores are 0 and vectors are empty
        for (int i = 0; i <= n; i++) {
            for (int k = 0; k <= 4; k++) {
                dp[i][k] = {0, {}};
            }
        }

        for (int i = 1; i <= n; i++) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: don't take current interval
                auto best = dp[i - 1][k];

                // Option 2: take current interval
                int prev = p[i - 1];

                long long score = a[i - 1][2];

                vector<int> indices;

                if (prev != -1) {
                    score += dp[prev + 1][k - 1].first;
                    indices = dp[prev + 1][k - 1].second;
                }

                indices.push_back((int)a[i - 1][3]);

                // Indices must be sorted for lexicographical comparison
                sort(indices.begin(), indices.end());

                pair<long long, vector<int>> take = {score, indices};

                // Choose higher score
                if (take.first > best.first) {
                    best = take;
                }
                // Same score -> lexicographically smaller
                else if (take.first == best.first &&
                         take.second < best.second) {
                    best = take;
                }

                dp[i][k] = best;
            }
        }

        return dp[n][4].second;
    }
};