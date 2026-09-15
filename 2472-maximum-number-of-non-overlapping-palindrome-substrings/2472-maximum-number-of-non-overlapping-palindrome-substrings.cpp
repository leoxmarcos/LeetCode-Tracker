class Solution {
private:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int max_count = 0;
        int last_end = -1; // Tracks the end index of the last picked palindrome

        for (int i = 0; i < n; i++) {
            // 1. Try to find a palindrome of exact length k ending at i
            if (i - k + 1 > last_end && isPalindrome(s, i - k + 1, i)) {
                max_count++;
                last_end = i;
            }
            // 2. Try to find a palindrome of exact length k + 1 ending at i
            else if (i - k > last_end && isPalindrome(s, i - k, i)) {
                max_count++;
                last_end = i;
            }
        }

        return max_count;
    }
};