class Solution {
public:
    int findComplement(int num) {
        bitset<32>b(num);
        string s=b.to_string();
        int first =s.find("1");
        for(int i=first ;i<s.size();i++)
        {
            if(s[i]=='0'){
                s[i]='1';
            }
            else{
                s[i]='0';
            }
        }
            bitset<32>ans(s);
            int res=ans.to_ulong();
            return res;
        
    }
};