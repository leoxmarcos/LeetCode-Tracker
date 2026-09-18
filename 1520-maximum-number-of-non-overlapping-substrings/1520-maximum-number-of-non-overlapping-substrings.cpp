class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int first[26], last[26];
        memset(first, -1, sizeof(first));
        memset(last, -1, sizeof(last));
        
        int n = s.length();
        // Step 1: Find the first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }
        
        vector<string> res;
        int right = -1;
        
        // Step 3: Greedily process valid substrings
        for (int i = 0; i < n; ++i) {
            if (i == first[s[i] - 'a']) {
                int new_right = getValidRightBoundary(s, i, first, last);
                if (new_right != -1) {
                    // Non-overlapping: starts after the current tracked right boundary
                    if (i > right) {
                        res.push_back("");
                    }
                    // Update tracked right boundary and overwrite the last added string. 
                    // This naturally handles replacing an outer valid substring with a smaller nested one.
                    right = new_right;
                    res.back() = s.substr(i, right - i + 1);
                }
            }
        }
        
        return res;
    }

private:
    // Step 2: Validate and find the rightmost boundary for a substring starting at index i
    int getValidRightBoundary(const string& s, int i, int first[], int last[]) {
        int right = last[s[i] - 'a'];
        for (int j = i; j <= right; ++j) {
            // If a character inside the range appeared before our start index 'i', it's invalid.
            if (first[s[j] - 'a'] < i) {
                return -1; 
            }
            // Expand the right boundary if the current character ends later
            right = max(right, last[s[j] - 'a']);
        }
        return right;
    }
};