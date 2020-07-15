#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ar = {1,2,1};
    int n = ar.size();
    long long rightSum = 0;
    long long leftSum = 0;
    for (int i = 0; i < n; ++i)
        rightSum += ar[i];

    for (int i = 0; i < n; ++i)
    {
        rightSum -= ar[i];
        
        if (leftSum == rightSum)
            return cout << i << endl, 0;

        leftSum += ar[i];
    }
    cout << -1 << endl;
    return 0;
}