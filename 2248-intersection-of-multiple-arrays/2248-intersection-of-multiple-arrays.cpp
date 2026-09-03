class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int>freq;
        
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                freq[nums[i][j]]++;
            }
        }
        vector<int>result;
        for(auto it:freq){
            if(it.second==nums.size()){
                result.push_back(it.first);
            }
        }
        if (result.empty()){
            return {};
        }
        return result;

    }
};
    