class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
           int sumSingle = 0, sumDouble = 0;

        for (int num : nums) {
            if (num < 10) {
                sumSingle += num;
            } else {
                sumDouble += num;
            }
        }

        return sumSingle != sumDouble;
    }
};