// https://www.geeksforgeeks.org/find-triplet-sum-two-equals-third-element/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ar = {5, 32, 1, 7, 10, 50, 19, 21, 2};
    sort(ar.begin(), ar.end());
    int n = ar.size();

    for (int i = n - 1; i >= 0; --i)
    {
        int l = 0, r = i - 1;
        int x = -ar[i];
        while (l < r)
        {
            if (x + ar[l] + ar[r] == 0)
            {
                cout << ar[i] << " " << ar[l] << " " << ar[r] << endl;
            }
            if (x + ar[l] + ar[r] < 0)
                ++l;
            else
                --r;
        }
    }
    return 0;
}