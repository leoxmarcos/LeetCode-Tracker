class Solution {
public:
    string interpret(string command) {
        string ans="";
        for(int i=0;i<command.size();i++){
            if(command[i]=='G'){
                ans+='G';
            }
            else if(command[i]=='('&& command[i+1]==')'){
                ans+='o';
                i=i+1;
            }
            else if(command[i]=='('&& command[i+1]=='a'&& command[i+2]=='l'&& command[i+3]==')') {
                ans+="al";
                i=i+1;
            }
        }
        return ans;
    }
};