
class Solution {
public:
    multiset<int> low, high;
    long long sumLow = 0, sumHigh = 0;

    void balance() {
        while(low.size() < high.size()) {
            int v = *high.begin();
            high.erase(high.begin());
            sumHigh -= v;

            low.insert(v);
            sumLow += v;
        }

        while(low.size() > high.size() + 1) {
            int v = *low.rbegin();
            low.erase(prev(low.end()));
            sumLow -= v;

            high.insert(v);
            sumHigh += v;
        }
    }

    void add(int v) {
        if(low.empty() || v <= *low.rbegin()) {
            low.insert(v);
            sumLow += v;
        }
        else {
            high.insert(v);
            sumHigh += v;
        }

        balance();
    }

    void remove(int v) {
        auto it = low.find(v);

        if(it != low.end()) {
            low.erase(it);
            sumLow -= v;
        }
        else {
            it = high.find(v);
            high.erase(it);
            sumHigh -= v;
        }

        balance();
    }

    long long cost() {
        long long mid = *low.rbegin();

        return mid * low.size() - sumLow
             + sumHigh - mid * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        for(int i = 1; i <= n; i++) {

            add(nums[i - 1]);

            for(int j = 0; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
            }

            if(i >= x) {
                long long c = cost();

                for(int j = 1; j <= k; j++) {
                    if(dp[i - x][j - 1] != INF) {
                        dp[i][j] = min(
                            dp[i][j],
                            dp[i - x][j - 1] + c
                        );
                    }
                }

                remove(nums[i - x]);
            }
        }

        return dp[n][k];
    }
};
