class Solution {
public:
void subseq(vector<int>& nums, int index, vector<vector<int>>& ans, vector<int>& temp) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Don't take the current element
        subseq(nums, index + 1, ans, temp);

        // Take the current element
        temp.push_back(nums[index]);
        subseq(nums, index + 1, ans, temp);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
          vector<vector<int>> ans;
        vector<int> temp;

        subseq(nums, 0, ans, temp);

        return ans;
    }
};