#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,a;
    cin>>n;
    vector<int> ans(n,-1);
    for(int i=0;i<n;++i){
        cin>>a;
        if(a < n)
            ans[a] = a;
    }
    for(int i=0;i<n;++i)
        if(ans[i] == -1){
            cout<<i<<endl;
            break;
        }
    return 0;
}