class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    
     int res=nums[0];
     int sumend=nums[0];
     for(int i=1;i<nums.size();i++){
        sumend=max(sumend+nums[i],nums[i]);
        res=max(res,sumend);
     }
     return res;
    }
};