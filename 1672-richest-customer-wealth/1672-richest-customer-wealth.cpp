class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
         int maxWealth = 0;

        for (auto &customer : accounts) {
            int sum = 0;
            for (int money : customer) {
                sum += money;
            }
            maxWealth = max(maxWealth, sum);
        }

        return maxWealth;
    }
};