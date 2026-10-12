class Solution {
public:
int maxSum(vector<int>& nums, int k) {
const int MOD = 1e9 + 7;
vector<int> cnt(31, 0);

    for (int num : nums) {
        for (int bit = 0; bit < 31; bit++) {
            if (num & (1 << bit)) {
                cnt[bit]++;
            }
        }
    }

    long long ans = 0;

    for (int i = 0; i < k; i++) {
        long long num = 0;

        for (int bit = 0; bit < 31; bit++) {
            if (cnt[bit] > 0) {
                num |= (1LL << bit);
                cnt[bit]--;
            }
        }

        ans = (ans + num * num) % MOD;
    }

    return ans;
}


};
