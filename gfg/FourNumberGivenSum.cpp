// https://www.geeksforgeeks.org/find-four-numbers-with-sum-equal-to-given-sum/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ar = {10, 2, 3, 4, 5, 9, 7, 8};
    int x = 23;
    int n = ar.size() - 1;
    for (int i = 0; i < n - 3; ++i)
    {
        for (int j = 0; j < n - 2; ++j)
        {
            int l = j + 1;
            int r = n - 1;
            while (l < r)
            {
                int sum = ar[i] + ar[j] + ar[l] + ar[r];
                if (sum == x)
                {
                    cout << ar[i] << " " << ar[j] << " " << ar[l] << " " << ar[r] << endl;
                }
                if (sum < x)
                    ++l;
                else
                {
                    --r;
                }
            }
        }
    }
    return 0;
}