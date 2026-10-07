class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> st;
        
        queue<string> q;
        q.push(s);
        
        bool found = false;
        
        while (!q.empty()) {
            string str = q.front();
            q.pop();
            
            if (isValid(str)) {
                ans.push_back(str);
                found = true;
            }
            
            if (found)
                continue;
            
            for (int i = 0; i < str.size(); i++) {
                if (str[i] != '(' && str[i] != ')')
                    continue;
                
                string temp = str.substr(0, i) + str.substr(i + 1);
                
                if (st.find(temp) == st.end()) {
                    st.insert(temp);
                    q.push(temp);
                }
            }
        }
        
        return ans;
    }
    
    bool isValid(string s) {
        int count = 0;
        
        for (char ch : s) {
            if (ch == '(')
                count++;
            else if (ch == ')') {
                count--;
                
                if (count < 0)
                    return false;
            }
        }
        
        return count == 0;
    }
};