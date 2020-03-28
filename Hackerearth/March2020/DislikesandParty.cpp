#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define ull long long
#define vi vector<int>

using namespace std;

bool In(int *ar, int element)
{
    for (int i = 0; i < 10; ++i)
        if (ar[i] == element)
            return true;
    return false;
}

int main(){
    FASTIO
        int a, c;
    cin >> a;
    int ar[10][10] = {0};
    map<int, int> sr_pos;
    map<int, bool> allno;

    for (int j = 0; j < 10; ++j)
    {
        for (int k = 0; k < 10; ++k)
        {
            cin >> c;
            ar[j][k] = c;
            allno[c] = true;
        }
        sr_pos[ar[j][0]] = j;
    }
    long long cnt = 0, sz = 0;
    int pos = -1, bity;
    for (auto itr = allno.begin(); itr != allno.end(); ++itr)
    {
        ++sz;
        int j = itr->first;
        bity = a - 1;
        // if (allno.find(j) != allno.end())
        {
            auto itr = sr_pos.find(j);
            pos = itr != sr_pos.end() ? itr->second : -1;

            if (pos != -1)
            {
                bity -= 9;
            }

            for (int k = 0; k < 10; ++k)
            {
                if (k == pos)
                    continue;
                if (pos != -1 && In(ar[pos], ar[k][0]))
                    continue;

                for (int z = 1; z < 10; ++z)
                {
                    if (j == ar[k][z])
                    {
                        if (pos == -1)
                        {
                            --bity;
                            continue;
                        }
                        --bity;
                        break;
                    }
                }
            }
        }
        cnt += bity;
    }
    cnt += (a - sz) * (a - 1);
    cout << (cnt / 2) << endl;
    return 0;
}