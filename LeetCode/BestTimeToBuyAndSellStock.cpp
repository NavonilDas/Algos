class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX,ans= 0;
        /**
            As We can on do one transaction choose a minimum number at index i
            find a number which is greater than choosen number and index > i
            the difference between the number is the maximum profit
        **/
        for(int p:prices){
            mn = min(p,mn);
            if(mn < p)
                ans = max(ans,(p - mn));
        }
        return ans;
    }
};