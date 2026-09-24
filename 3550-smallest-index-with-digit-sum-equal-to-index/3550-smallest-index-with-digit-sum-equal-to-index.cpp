class Solution {
public:
    int smallestIndex(vector<int>& nums) {
         
    
        for(int i=0;i<nums.size();i++){
            int sum=0;
       
             while(nums[i]>0)
            {
                int rem = nums[i]%10;
                sum = sum + rem;
                nums[i] = nums[i]/10;
            }
            if(i==sum)
            return i;
        }
        return -1;
       
    }
         
};