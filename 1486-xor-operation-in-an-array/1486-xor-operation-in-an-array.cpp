class Solution {
public:
    int xorOperation(int n, int start) {
        int arr[n],XOR=0;
        for(int i =0;i<n; i++){
            arr[i]=start + 2*i;
            XOR^=arr[i];
         }
         return XOR;
    }
};