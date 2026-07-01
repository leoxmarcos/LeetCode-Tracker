class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            // Subtract 1 to adjust for Excel's 1-based indexing
            columnNumber--;
            
            // Map the remainder (0-25) to its corresponding character ('A'-'Z')
            char current_char = 'A' + (columnNumber % 26);
            result += current_char;
            
            // Move to the next digit position
            columnNumber /= 26;
        }
        
        // The characters are collected from right to left, so reverse the string
        reverse(result.begin(), result.end());
        
        return result;
    }
};;