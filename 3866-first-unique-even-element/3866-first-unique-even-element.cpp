class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
          unordered_map<int, int> freq;

        for(int x : nums) {
            freq[x]++;
        }

        for(int x : nums) {
            if(x % 2 == 0 && freq[x] == 1) {
                return x;
            }
        }

        return -1;
    }
};