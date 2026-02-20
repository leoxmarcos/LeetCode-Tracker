class Solution {
public:
    string reverseWords(string s) {

        string result="";
        string word="";
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if(word != "") {                
                    if(result == "")
                        result = word;
                    else
                        result = word + " " + result;
                    word = "";
                }
            }
            else {                               
                word += s[i];
            }
        }

     
        if(word != "") {
            if(result == "")
                result = word;
            else
                result = word + " " + result;
        }

        return result;
        
    }
};