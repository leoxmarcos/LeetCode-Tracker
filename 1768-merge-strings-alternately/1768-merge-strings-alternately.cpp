class Solution {
public:
    string mergeAlternately(string word1, string word2) {
         int n =word1.size();
    int m = word2.size();
    int size = max(n, m);
    string str = "";
    for(int i=0; i<size; i++){
        if(i<n) str += word1[i];
        if(i<m) str += word2[i];
        
    }
    return str;
    }
};