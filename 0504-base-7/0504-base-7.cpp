class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        
        bool is_negative = num < 0;
        num = abs(num);
        string base7 = "";
        
        while (num > 0) {
            base7 += to_string(num % 7);
            num /= 7;
        }
        
        if (is_negative) {
            base7 += "-";
        }
        
        reverse(base7.begin(), base7.end());
        return base7;
    }
};