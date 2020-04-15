#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    if(k > (int)num.size()) return "0";
    int p = -1, i = 0, n = num.size();
    string ans = num;
    while (i < n)
    {
        while (p > -1 && k > 0 && ans[p] > num[i])
        {
            // cout<<"stuck 0\n";
            --p;
            --k;
        }
        ans[++p] = num[i];
        ++i;
    }
    while (k > 0)
    {
        // cout<<"stuck 1\n";
        --p;
        --k;
    }

    ans[++p] = '\0';
    i = 0;
    while (i < n)
    {
        // cout<<"stuck 2\n";
        if (ans[i] == '0')
            ++i;
        else
            break;
    }
    // cout<<i<<" "<<p<<endl;
    if(p == 0 || (p - i)==0)
        return "0";
    return ans.substr(i, p);
}
int main()
{
    cout<<removeKdigits("10",2)<<endl;
    return 0;
}