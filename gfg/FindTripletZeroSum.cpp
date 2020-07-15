// https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> ar = {0, -1, 2, -3, 1};
    sort(ar.begin(), ar.end());
    int n = ar.size();
    for (int i = 0; i < n; ++i)
    {
        int l = i + 1, r = n - 1;
        int x = ar[i];
        while (l < r)
        {
            if (x + ar[l] + ar[r] == 0)
            {
                cout << ar[i] << " " << ar[l] << " " << ar[r] << endl;
                return 0;
            }
            if (x + ar[l] + ar[r] < 0)
                ++l;
            else
                --r;
        }
    }
    return 0;
}