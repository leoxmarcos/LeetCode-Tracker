class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(char c : s) {
            if(c == '(') {
                st.push(0);
            }
            else {
                int x = st.top();
                st.pop();

                int val;
                if(x == 0)
                    val = 1;
                else
                    val = 2 * x;

                st.top() += val;
            }
        }

        return st.top();
    }
};