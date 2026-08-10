class Solution {
public:

  int num(char c)
  {
    if(c=='I')
    return 1;
    else if(c=='V')
    return 5;
     else if(c=='X')
    return 10;
     else if(c=='L')
    return 50;
     else if(c=='C')
    return 100;
     else if(c=='D')
    return 500;
     else 
    return 1000;

  }
    int romanToInt(string s) {
        //      unordered_map<char, int> value = {
        //     {'I', 1},
        //     {'V', 5},
        //     {'X', 10},
        //     {'L', 50},
        //     {'C', 100},
        //     {'D', 500},
        //     {'M', 1000}
        // };

        // int ans = 0;

        // for (int i = 0; i < s.length(); i++) {
        //     // If current value is smaller than next value
        //     if (i + 1 < s.length() && value[s[i]] < value[s[i + 1]]) {
        //         ans -= value[s[i]];
        //     } else {
        //         ans += value[s[i]];
        //     }
        // }

        // return ans;

   int sum =0,index=0;
   
   while (index<s.size()-1){
    if(num(s[index])<num(s[index+1]))
     sum-=num(s[index]);
     else
     sum+=num(s[index]);
     index++;
   }
   
   sum+=num(s[index]);
   return sum;
   
   
   
   
    }


};