// class Solution {
// public:
//     string sortSentence(string s) {
//         vector<string>ans(10);
//         string temp;
//         int count=0;
//         int index=0;
//         while(index < s.size())
//         {
//              if(s[index]==' ')
//              {
//                 int pos =temp[temp.size()-1]- '0';
//                 temp.pop_back();
//                 ans[pos]=temp;
//                 temp.clear();
//                 count++;
//              }
//              else
//              {
//                 temp+=s[index];
//                 index++;
//              }
//         }

//               int pos =temp[temp.size()-1]-'0';
//                 temp.pop_back();
//                 ans[pos]=temp;
//                 temp.clear();
//                 count++;
//         for(int i=1;i<=count;i++){
//             temp+=ans[i];
//             temp+=' ';
//              temp.pop_back();
//         }
//        return temp;
//     }
// };

// class Solution {
// public:
//     string sortSentence(string s) {
//         vector<string> ans(10);
//         string temp;
//         int count = 0;
//         int index = 0;

//         while (index < s.size()) {
//             if (s[index] == ' ') {
//                 int pos = temp.back() - '0';
//                 temp.pop_back();
//                 ans[pos] = temp;
//                 temp.clear();
//                 count++;
//                 index++;           // Fixed
//             } else {
//                 temp += s[index];
//                 index++;
//             }
//         }

//         int pos = temp.back() - '0';
//         temp.pop_back();
//         ans[pos] = temp;
//         count++;

//         temp.clear();

//         for (int i = 1; i <= count; i++) {
//             temp += ans[i];
//             if (i != count)
//                 temp += ' ';
//         }

//         return temp;
//     }
// };



class Solution {
public:
    string sortSentence(string s) {
        vector<pair<int,string>> v;
        string word;

        for(char c : s + ' ') {
            if(c == ' ') {
                int pos = word.back() - '0';
                word.pop_back();
                v.push_back({pos, word});
                word.clear();
            } else {
                word += c;
            }
        }

        sort(v.begin(), v.end());

        string ans;
        for(auto &p : v)
            ans += (ans.empty() ? "" : " ") + p.second;

        return ans;
    }
};