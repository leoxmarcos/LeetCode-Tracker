class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        int freq[10] = {0};

        // Count frequency of every digit
        for(int x : digits) {
            freq[x]++;
        }

        int ans = 0;

        // Hundreds digit
        for(int i = 1; i <= 9; i++) {
            
            // Tens digit
            for(int j = 0; j <= 9; j++) {
                
                // Units digit must be even
                for(int k = 0; k <= 8; k += 2) {
                    
                    int need[10] = {0};
                    need[i]++;
                    need[j]++;
                    need[k]++;

                    bool possible = true;

                    for(int d = 0; d <= 9; d++) {
                        if(need[d] > freq[d]) {
                            possible = false;
                            break;
                        }
                    }

                    if(possible) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};