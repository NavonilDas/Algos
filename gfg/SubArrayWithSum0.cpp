#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> ar = {-3, 2, 3, 1, 6};
    int n = ar.size();
    map<long long, int> hsh;
    long long sum = 0;
    bool flag = false;
    for (int i = 0; i < n; ++i)
    {
        sum += ar[i];
        if (sum == 0)
        {
            cout << "Exist at 0 - " << i << endl;
            flag = true;
        }
        else
        {
            if (hsh.find(sum) != hsh.end())
            {
                flag = true;
                cout << "Exist at " << (hsh.at(sum) + 1)
                     << " - " << i << endl;
            }
        }
        hsh[sum] = i;
    }
    if (!flag)
    {
        cout << "Not Exists :(\n";
    }
    return 0;
}