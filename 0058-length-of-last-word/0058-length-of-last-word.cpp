class Solution {
public:
    int lengthOfLastWord(string s) {
        int count =0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' '){
                if(count>0){
                    break;
                }
            }
            else{
                count++;
            }
        }
        return count;
    }
};