// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//          int n=nums.size();
// int i=0;
// int a=0;
// while(a<n-1)
// {
// for(int i=0;i<n-1;i++){
// if(nums[i]==0){
// int temp=nums[i];
// nums[i]=nums[i+1];
// nums[i+1]=temp;
// }
// }
// a++;
// }
//     }
// };


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};