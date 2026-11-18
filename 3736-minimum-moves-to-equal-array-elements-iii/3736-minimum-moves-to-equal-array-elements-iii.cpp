class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = 0;
        int sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            sum += nums[i];
        }

        return mx * n - sum;
    }
};