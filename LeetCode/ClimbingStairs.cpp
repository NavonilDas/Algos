class Solution {
public:
    int climbStairs(int n) {
        // fibonacci numbers
        if(n <= 1) return 1;
        if(n == 2) return 2;
        int f = 1,s = 1;
        for(int i=1;i<n;++i){
            int t = f + s;
            f = s;
            s = t;
        }
        return s;   
    }
};