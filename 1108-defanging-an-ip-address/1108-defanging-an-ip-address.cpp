class Solution {
public:
    string defangIPaddr(string address) {
        // int index=0;
        // string ans;
        // while(index <address.size())
        // {
        //     if(address[index]=='.')
        //     ans=ans+"[.]";
        //     else
        //     ans=ans+address[index];
        //     index++;
        // }
        // return ans;
        int n=address.size();
        string ans;
        for(int i=0;i<address.size();i++)
        {
            if(address[i]=='.'){
                ans+="[.]";
            }
            else{
                ans+=address[i];
            }
        }
        return ans;
    }
};