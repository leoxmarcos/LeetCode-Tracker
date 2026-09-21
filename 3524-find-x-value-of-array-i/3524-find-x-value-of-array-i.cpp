class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
       vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next(k, 0);

            int x = num % k;

            // Start a new subarray
            next[x]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int newR = (r * x) % k;
                next[newR] += dp[r];
            }

            // Add all subarrays ending here to answer
            for (int r = 0; r < k; r++) {
                ans[r] += next[r];
            }

            dp = next;
        }

        return ans;  
    }
};