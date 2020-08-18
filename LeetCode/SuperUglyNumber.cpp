class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 0) return 1;
        vector<int> pos(primes.size(),0);
        vector<long long> dp(n+1,0);
        dp[0] = 1;
        
        for(int i=1;i<n;++i){
            int tmp = INT_MAX;
            
            for(int j=0;j<pos.size();++j){
                // cout<<i<<" "<<pos[j]<<" "<<dp[ pos[j] ]<<endl;
                tmp = min((long long)tmp,dp[ pos[j] ] * primes[j]);
            }
            dp[i] = tmp;
            for(int j=0;j<pos.size();++j){
                if(dp[i] == (dp[pos[j]]*primes[j]) ) ++pos[j];
            }
        //     pq.push(tmp);
        }
        // while(!pq.empty()){
        //     cout<<pq.top()<<" ";
        //     pq.pop();
        // }
        // cout<<endl;
        // for(int i:dp){
        //     cout<<i<<" ";
        // }
        return dp[n-1];
    }
};