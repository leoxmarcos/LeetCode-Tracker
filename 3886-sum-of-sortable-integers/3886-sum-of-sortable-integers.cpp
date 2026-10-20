
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, INT_MAX);
        vector<int> drop(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        for (int i = 1; i < n; i++) {
            drop[i + 1] = drop[i] + (nums[i - 1] > nums[i]);
        }

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            bool valid = true;

            for (int i = 0; i < n; i += k) {
                int j = i + k - 1;

                // Check whether previous blocks can
                // come before the current block.
                if (i > 0 && prefMax[i] > suffMin[i]) {
                    valid = false;
                    break;
                }

                // Count descending adjacent pairs
                // inside the current block.
                int descents = drop[j + 1] - drop[i + 1];

                // Include the circular boundary.
                if (nums[j] > nums[i]) {
                    descents++;
                }

                if (descents > 1) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};
