class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char> st;
        int count = 0;

        for (char ch : s) {

            if (ch == '(') {
                st.push(ch);
            }
            else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    count++;
                }
            }
        }

        return count + st.size();
    }
};

      

        // int openBrack=0;
        // int closeBrack=0;
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='(')
        //     openBrack++;

        //     if(s[i]==')')
        //     closeBrack++;
        // }
        // int count=abs(openBrack-closeBrack);
        // return count;


