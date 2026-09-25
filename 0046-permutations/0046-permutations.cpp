
class Solution {
public:
    
    void permut(vector<int>& arr, vector<vector<int>>& ans, int index){
        if(index==arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int i =index;i<arr.size();i++){
            swap(arr[i],arr[index]);
            permut(arr,ans,index+1);
            swap(arr[i],arr[index]);
        }
        
    }
    //             vector<int> temp, vector<bool> visited) {
        
    //     if(temp.size() == arr.size()) {
    //         ans.push_back(temp);
    //         return;
    //     }
        
    //     for(int i = 0; i < arr.size(); i++) {
    //         if(visited[i] == 0) {
                
    //             visited[i] = 1;
    //             temp.push_back(arr[i]);
                
    //             permut(arr, ans, temp, visited);
                
    //             visited[i] = 0;
    //             temp.pop_back();
    //         }
    //     }
    // }
    
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<vector<int>> ans;
        // vector<int> temp;
        // vector<bool> visited(nums.size(), 0);
        
        // permut(nums, ans, temp, visited);
        
        // return ans;
          vector<vector<int>> ans;
        
        
        permut(nums,ans,0);
        
        return ans;
    }
};