class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    

   int largestSum = nums[0]; 
        int currSum = 0;
        
        for(int num : nums) {
            if (currSum < 0) currSum = 0; 
            currSum += num;
            largestSum = max(largestSum, currSum);
        }
        
        return largestSum;
    }
};