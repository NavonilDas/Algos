#define ll long long

class Solution {
public:
    const ll MOD = 1e9 + 7;
    
/*    ll rec(int d,ll cur_sum,int &f,int &target){
        if(cur_sum > target) return 0;
        if(d == 0) {
            // cout<<"yes\n";
            return (cur_sum == target);
        }
        if(dp[d][cur_sum] != -1){
            // cout<<"oh\n";
            return dp[d][cur_sum]%MOD;            
        }
        ll cnt = 0;
        for(int i=1;i<=f;++i){
            ll tmp = rec(d-1,cur_sum+i,f,target);
            cnt = (cnt + tmp)%MOD;
        }
        return dp[d][cur_sum] = cnt%MOD;
    }
    */ll bottomUp(int d, int f, int target){
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1; // When 0 rolls and sum is also zero
        // Roll Dice d times
        for(int roll = 1; roll <= d; ++roll){           
            // Check for all sums upto target
            for(int sum=1;sum<=target;++sum){
                // f possiblities
                for(int face=1;face <= f; ++face){
                    // if we choose a face whose sum is more than sum then our sum is not possible                    
                    if(face > sum) break;
                    
                    // if we choose a face then we have to add the number of ways to make sum - face to get sum
                    dp[roll][sum] += dp[roll - 1][sum - face];
                    if(dp[roll][sum] >= MOD)
                        dp[roll][sum] -= MOD;
                    if(dp[roll][sum] < 0)
                        dp[roll][sum] += MOD;
                }
                
            }
        }
        
        return dp[d][target];
    }
    int numRollsToTarget(int d, int f, int target) {
        // For Recursion
        // ll dp[40][1007];
        // memset(dp,-1,sizeof(dp));
        // return rec(d,0,f,target);
        
        return bottomUp(d,f,target);
    }
};