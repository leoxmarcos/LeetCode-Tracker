class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, 1e9);

        int left = 0, sum = 0;
        int ans = 1e9;
        int minLen = 1e9;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;

                // Check if there was a previous non-overlapping subarray
                if (left > 0 && best[left - 1] != 1e9) {
                    ans = min(ans, len + best[left - 1]);
                }

                minLen = min(minLen, len);
            }

            best[right] = minLen;
        }

        return ans == 1e9 ? -1 : ans;
    }
};