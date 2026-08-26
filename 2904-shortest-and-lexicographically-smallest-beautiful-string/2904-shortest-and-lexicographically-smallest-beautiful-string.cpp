class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int ones = 0;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1') {
                ones++;
            }

            // Remove extra 1's
            while (ones > k) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }

            // Remove leading 0's to make substring shorter
            while (ones == k && left < right && s[left] == '0') {
                left++;
            }

            if (ones == k) {
                string current = s.substr(left, right - left + 1);

                if (ans == "" ||
                    current.length() < ans.length() ||
                    (current.length() == ans.length() && current < ans)) {
                    
                    ans = current;
                }
            }
        }

        return ans;
    }
};