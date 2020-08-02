#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1,r = (num>>1),mid;
        long long ans = 1;
        while(l <= r){
            mid = (l+r) >> 1;
            ans = mid*mid;
            if(ans == num){
                return true;
            }
            if(ans > num){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
        cout <<" +=> "<< (long long)(pow(2,31)-1) << endl;
    s.isPerfectSquare(4);
    return 0;
}