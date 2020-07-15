// https://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> ar1 = {1, 4, 5, 7};
    vector<int> ar2 = {10, 20, 30, 40};
    int x = 32, n = ar1.size();
    int i = 0, j = n - 1;
    int ansa = -1, ansb = -1, ak = 1e7;
    while (i < n && j >= 0)
    {
        int tmp = abs(ar1[i] + ar2[j] - x);
        if (tmp < ak)
        {
            ak = tmp;
            ansa = i;
            ansb = j;
        }

        if (ar1[i] + ar2[j] < x)
            ++i;
        else
            --j;
    }
    if (ansa != -1 && ansb != -1)
    {
        cout << " " << ar1[ansa] << " + " << ar2[ansb] << "\n";
    }
    return 0;
}