#include <bits/stdc++.h>
using namespace std;
// Use memory
bool mem(string &a, string &b)
{
    stack<char> crap1;
    stack<char> crap2;
    for (char &c : a)
    {
        if (c == '#')
        {
            if (!crap1.empty())
                crap1.pop();
        }
        else
            crap1.push(c);
    }
    for (char &c : b)
    {
        if (c == '#')
        {
            if (!crap2.empty())
                crap2.pop();
        }
        else
        {
            crap2.push(c);
        }
    }

    // cout << crap1.size() << " " << crap2.size() << endl;

    if (crap1.size() != crap2.size())
        return false;
    else
    {
        while (!crap1.empty() && !crap2.empty())
        {
            if (crap1.top() != crap2.top())
                return false;
            crap1.pop();
            crap2.pop();
        }
    }
    return true;
}
bool save(string &a, string &b)
{
    int l = 0, r = 0;
    int n = a.size();
    while (r < n)
    {
        if (a[r] == '#')
        {
            a[r] = '$';
            if (l >= 0)
                a[l] = '$';
            --l;
        }
        else if(a[r] == '$'){
            ++r;
        }
        else
        {
            l = r;
            ++r;
        }
    }
    cout << a << endl;
    return true;
}
int main()
{
    string a = "ab##", b = "c#d";
    // cin >> a >> b;
    cout << mem(a, b) << endl;
    cout << save(b,a) << endl;
    return 0;
}