class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);

        int maxFreq = 0;

        // Count frequency
        for (int x : nums) {
            freq[x]++;
            maxFreq = max(maxFreq, freq[x]);
        }

        // Calculate answer
        int ans = 0;

        for (int i = 0; i <= 100; i++) {
            if (freq[i] == maxFreq) {
                ans += freq[i];
            }
        }

        return ans;
    }
};