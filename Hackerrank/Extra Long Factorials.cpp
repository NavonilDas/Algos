#include <bits/stdc++.h>

using namespace std;
string multiply(string a,string b){
    int n1 = a.size();
    int n2 = b.size();
    if(n1 == 0 || n2 == 0) return "0";
    vector<int> res(n1+n2,0);
    int x=0,y =0;
    for(int i=n1-1;i>=0;i--){
        int c = 0;
        y = 0;
        int na = a[i]-'0';
        for(int j=n2-1;j>=0;j--){
            int nb = b[j]-'0';
            int sum = res[x+y] + na*nb + c;
            c = sum/10;
            res[x+y++] = sum%10;
        }
        if(c > 0) res[x+y] +=c;
        ++x;
    }
    int i = res.size()-1;
    while(i >= 0 && res[i] == 0)
        --i;
    if(i==-1) return "0";
    string s="";
    while(i>=0)
        s+=to_string(res[i--]);
    return s;
}
// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    string res = "1";
    for(int i=n;i>=2;i--)
        res = multiply(res,to_string(i));
    cout<<res<<endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
