class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // Optimal Statergy to pick a game
        const int n = piles.size();
        
        // first is alex , second is lee in the pair
        vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(n+1));
        for(int i=0;i<n;++i){
            dp[i][i] = make_pair(piles[i],0);
        }
        for(int len=2;len<=n;++len){
            for(int i=0;i<=n-len;++i){
                int j = i + len - 1;
                
                int left = dp[i+1][j].second + piles[i];
                int right = dp[i][j-1].second + piles[j];
                
                if(left > right){
                    dp[i][j].first = left;
                    dp[i][j].second = dp[i+1][j].first;
                }else{
                    dp[i][j].first = right;
                    dp[i][j].second = dp[i][j-1].first;                    
                }
            }
        }
        /*
        for(int i=0;i<n;++i){
            for(int k=i+1;k<n;++k){
                dp[i][j].first = max(
                    dp[i+1][j].second + piles[i],
                    dp[i][j-1].second + piles[j]
                );
                dp[i][j].second = max(
                    dp[i+1][j].first,
                    dp[i][j-1].first
                );
            }
        }
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                cout<<"("<<dp[i][j].first<<","<<dp[i][j].second<<") ";
            }
            cout<<endl;
        }*/
        return dp[0][n-1].first > dp[0][n-1].second;
    }
};