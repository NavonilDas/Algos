// https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> ar = {1, 2, 3, 4, 5};
    sort(ar.begin(), ar.end());
    int n = ar.size();
    int sum = 9;
    for (int i = 0; i < n; ++i)
    {
        int l = i + 1, r = n - 1;
        int x = ar[i] - sum;
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