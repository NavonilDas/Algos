class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp = {
            1, // 0
            9, // 1
            81, // 2
            9*9*8, // 3
            9*9*8*7, // 4
            9*9*8*7*6, // 5
            9*9*8*7*6*5, // 6
            9*9*8*7*6*5*4, // 7
            9*9*8*7*6*5*4*3, // 8
            9*9*8*7*6*5*4*3*2, // 9
        };
        int ans = 0;
        for(int i=n;i>=0;--i){
            ans += dp[i];
        }
        return ans;
    }
};