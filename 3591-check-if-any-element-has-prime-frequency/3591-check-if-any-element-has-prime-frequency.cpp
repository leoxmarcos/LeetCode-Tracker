class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        
        int freq[101] = {0};

        // Count frequency
        for(int x : nums) {
            freq[x]++;
        }

        // Check every frequency
        for(int i = 0; i <= 100; i++) {
            
            int n = freq[i];

            if(n < 2)
                continue;

            bool prime = true;

            for(int j = 2; j * j <= n; j++) {
                if(n % j == 0) {
                    prime = false;
                    break;
                }
            }

            if(prime)
                return true;
        }

        return false;
    }
};