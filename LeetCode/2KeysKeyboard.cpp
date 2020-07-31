class Solution {
public:
    int minSteps(int n) {
        int ans = 0,d = 2;
        /**
        our startegy is to find the highest divisor of n because then we require
        n / (highest divisor) paste operation which is minmum
        now our problem breaks into finding the minimum number of steps to create 
        the word of length highest divisor ie. a recursion
        
        minSteps(n) = (n/highest_divisor) + minSteps(highest_divisor)
        
        if n is prime (2,3) the number of steps will equal to the number itself
        ie. Copy once and paste remaining
        
        The below solution is bottom up approach to solve the problem
        **/
        while(n > 1){
            while(n%d == 0){
                ans += d;
                n/=d;
            }
            ++d;
        }
        return ans;
    }
};