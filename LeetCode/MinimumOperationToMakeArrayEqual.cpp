class Solution {
public:
    int minOperations(int n) {
        int mid = n >> 1;
        return mid * (mid + (n&1) );
//         int mid = 0,mid2 = 0;
//         if(n&1) {
//             mid = n / 2;
//             mid = 2*mid + 1;
//             // cout<<mid<<endl;
//         }
//         else{
//             mid = n/2;
//             mid2 = (n-1)/2;
            
//             mid = 2*mid + 1;
//             mid2 = 2*mid2 + 1;
//             // cout<<mid<<" "<<mid2<<endl;
//         }
//         int costA = 0,costB = 0;
//         for(int i=0;i<n;++i){
//             costA += abs((2*i + 1)   - mid);
//             costB += abs((2*i + 1)   - mid2);
//         }
//         return min(costA,costB)/2;
    }
};