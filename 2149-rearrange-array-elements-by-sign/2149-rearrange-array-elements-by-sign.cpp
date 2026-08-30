class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
         vector<int> pos, neg, ans;

         // 1. Separate positive and negative elements
         for(int i = 0; i < arr.size(); i++) {
             if(arr[i] >= 0) {
                 pos.push_back(arr[i]);
             } else {
                 neg.push_back(arr[i]);
             }
         }

         // 2. Alternate them into the ans array
         int i = 0, j = 0;
         while(i < pos.size() && j < neg.size()) {
             ans.push_back(pos[i++]);
             ans.push_back(neg[j++]);
         }

         // 3. Append any remaining positive numbers
         while(i < pos.size()) {
             ans.push_back(pos[i++]);
         }

         // 4. Append any remaining negative numbers
         while(j < neg.size()) {
             ans.push_back(neg[j++]);
         }

         return ans;
    }
};