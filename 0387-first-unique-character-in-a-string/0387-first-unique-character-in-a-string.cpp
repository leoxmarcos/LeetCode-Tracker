class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> fre(26, 0);
        for (int i = 0; i < s.size(); i++) {
            fre[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (fre[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};