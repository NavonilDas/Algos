#include<bits/stdc++.h>
using namespace std;
struct mycmp
{
    inline bool operator() (const vector<int>& a, const vector<int>& b)
    {
        return (a[0] < b[0]);
    }
};

int main() {
	int n;
    cin>>n;
    vector<vector<int> > ar(n);
    for(int i=0;i<n;++i){
		ar[i] = vector<int>(2);
        cin>>ar[i][0]>>ar[i][1];
    }
    sort(ar.begin(),ar.end(),mycmp());
    bool flag = true;
    for(int i=0;i<ar.size()-1;++i){
        if(ar[i][1] >= ar[i+1][0]){
            flag = false;
            break;
        }
    }
    if(flag)
        cout<<"true\n";
    else
        cout<<"false\n";

    return 0;
}
