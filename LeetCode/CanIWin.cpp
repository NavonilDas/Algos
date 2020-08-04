class Solution {
public:
    bool backTrack(int total,int desired,int k,map<int,bool> &memo){
        if(desired <= 0) return false;
        // Check
        if(memo.find(k) != memo.end())
            return memo[k];
        
        for(int i=0;i<total;++i){
            if((k >> i)&1) continue;
            
            // k |= (1 << i);
            bool x = backTrack(total,desired - i - 1,(k|(1<<i)),memo);
            // k &= ~(1 << i);
            if(!x){
                memo[k] = true;
                return true;
            }
            memo[k] = false;
        }
        
        return memo[k];
    }
    // n is maxChoosableInteger
    bool canIWin(int n, int desiredTotal) {
        // const int n = 
        const int sum = ((n*(n+1))/2);
        if(desiredTotal <= 0) return true;
        if( sum < desiredTotal) return false;
        if(sum == desiredTotal) return n&1;
        if(n < 2) return true;
        
        map<int,bool> hsh;
         bool ans = backTrack(n,desiredTotal,0,hsh);
        hsh.clear();
        return ans;
    }
};