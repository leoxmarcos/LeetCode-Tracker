class Solution {
public:
    int majorityElement(vector<int>& nums) {
            sort(nums.begin(),nums.end());
    if(nums.size()==1)
    {
        return nums[0];
    }
    int count=0,value=INT_MIN,maxi,recode=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==value)
        {
            count++;
            if(count>recode)
            {
                maxi=value;
                recode=count;
            }
        }
        else
        {
            value=nums[i];
            count=1;
        }
    }
    return maxi;

    
}
    
};