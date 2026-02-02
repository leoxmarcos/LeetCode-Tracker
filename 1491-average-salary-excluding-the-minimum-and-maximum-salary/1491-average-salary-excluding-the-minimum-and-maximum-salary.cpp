class Solution {
public:
    double average(vector<int>& salary) {
      
         int minSalary = INT_MAX;
        int maxSalary = INT_MIN;
        int sum = 0;

        for(int i = 0; i < salary.size(); i++) {
            sum += salary[i];
            minSalary = min(minSalary, salary[i]);
            maxSalary = max(maxSalary, salary[i]);
        }

        return (double)(sum - minSalary - maxSalary) / (salary.size() - 2);
        
    } 
};