#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        /**
        
        For Substring j to i
        the we can break the recursive function as
        
        wordBreak(0 to j) and Subtring j to i is in Dictonary and wordBreak(i to end)
        
        now we can use dynamic programming to solve the problem
        
        **/
        const int n = s.size();
        if (n == 0)
            return true;
        if (wordDict.size() == 0)
            return false;
        map<string, bool> hsh;
        for (auto &a : wordDict)
        {
            hsh[a] = true;
        }
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            // All substring till 0 - i
            // in reverse order ie. suppose i = 3
            // the sequence will be 2,3 => 1,3 => 0,3
            // Then check if we can break the word upto j
            // if yes then check if the substring is present on hash
            // if it is also present then we dont care about further substring
            // so basically we are checkin wordBreak_upto(i) = wordBreak_upto(j) + is substring(j,i) is present on hash
            // foreach j from 0 to i-1
            // We do a Bottom up approach
            // word break of length 0 ie. Empty String is true 
            // answer is when i = n ie. dp[n]
            for (int j = i - 1; j >= 0; --j)
            {
                if (!dp[j])
                    continue;
                string a = s.substr(j, i - j);
                dp[i] = hsh.find(a) != hsh.end();
                if (dp[i])
                    break;
                // // cout << (i - j) << endl;
                // cout << i << "," << j << "  " << s.substr(j, i - j) << endl;
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    vector<string> a = {"a", "b", "c"};
    // vector<string> b = {};
    assert(s.wordBreak("abc", a) == true);
    assert(s.wordBreak("adc", a) == false);
    return 0;
}