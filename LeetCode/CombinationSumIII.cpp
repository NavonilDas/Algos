#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Back(int k, int start, int sum, vector<int> &tmp, vector<vector<int>> &ans)
    {
        if (k == 0)
        {
            if (sum == 0)
            {
                ans.push_back(tmp);
            }
            return;
        }
        for (int i = start; i <= 9; ++i)
        {
            tmp.push_back(i);
            Back(k - 1, i + 1, sum - i, tmp, ans);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        Back(k, 1, n, tmp, ans);
        return ans;
    }
};

int main()
{
    Solution s;
    auto x = s.combinationSum3(3, 9);
    for (auto a : x)
    {
        for (int b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}