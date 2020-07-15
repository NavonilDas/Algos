// https://www.geeksforgeeks.org/given-sorted-array-number-x-find-pair-array-whose-sum-closest-x/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ar = {1, 3, 4, 7, 10};
    int n = ar.size();
    int i = 0, j = n - 1;
    int x = 15, diff = 1e7, ansa = -1, ansb = -1;
    while (i < n && j >= 0)
    {
        int tmp = abs(ar[i] + ar[j] - x);
        if (tmp < diff)
        {
            diff = tmp;
            ansa = i;
            ansb = j;
        }
        if (ar[i] + ar[j] < x)
            ++i;
        else
        {
            --j;
        }
    }
    if (ansa != -1 && ansb != -1)
    {
        cout << ar[ansa] << " " << ar[ansb] << endl;
    }
    return 0;
}