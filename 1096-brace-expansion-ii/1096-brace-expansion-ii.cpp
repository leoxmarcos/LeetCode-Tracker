class Solution {
public:
    set<string> solve(string s, int &i) {
        set<string> result;
        result.insert("");

        while (i < s.size() && s[i] != '}') {
            set<string> part;

            if (s[i] == '{') {
                i++;
                part = solve(s, i);
                i++; // skip '}'
            }
            else {
                part.insert(string(1, s[i]));
                i++;
            }

            set<string> temp;

            for (string a : result) {
                for (string b : part) {
                    temp.insert(a + b);
                }
            }

            result = temp;

            if (i < s.size() && s[i] == ',') {
                i++;

                set<string> next = solve(s, i);

                result.insert(next.begin(), next.end());
                break;
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};