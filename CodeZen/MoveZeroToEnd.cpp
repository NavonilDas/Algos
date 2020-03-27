#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
    cin>>n;
    vector<int> ar(n);
    for(int i=0;i<n;++i)
        cin>>ar[i];
   	int s = 0,e = 1;
    while(e < n){
        if(ar[s] == 0 && ar[e] != 0){
            ar[s++] = ar[e];
            ar[e++] = 0;
        }
        if(ar[e] == 0)
            ++e;
        if(ar[s] != 0){
            ++s;
            if(e < s) e = s+1;
        }
    }
    for(int i=0;i<n;++i)
        	cout<<ar[i]<<" ";
	// Write your code here
}