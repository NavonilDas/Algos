#include<bits/stdc++.h>
using namespace std;

void insert(vector<vector<int>> &ar,int a,int b,int pos){
    for(int i=0;i<ar.size();++i){
        if(i == pos){
            cout<<a<<" "<<b<<endl;
        }
        cout<<ar[i][0]<<" "<<ar[i][1]<<endl;
    }
}
bool inRange(vector<int> &ar,int a){
    return (a >= ar[0] && a <= ar[1]);
}
int main() {
	int n,a,b;
    cin>>n;
    vector<vector<int>> ar(n);
    for(int i=0;i<n;++i){
        ar[i] = vector<int>(2);
        cin>>ar[i][0]>>ar[i][1];
    }
    cin>>a>>b;
    bool flag = true;
    int start = -1,end = -1;
    for(int i=0;i<ar.size()-1;++i){
        if(start != -1 && end != -1) break;

        if(ar[i][1] < a && ar[i+1][0] > b){
            insert(ar,a,b,i+1);
            // break;
            return 0;
        }
        if(start == -1 && inRange(ar[i],a)){
            a = min(a,ar[i][0]);
            start = i;
            continue;
        }
        if(start == -1 && inRange(ar[i+1],a)){
            a = min(a,ar[i+1][0]);
            start = i+1;
            continue;
        }
        if(start == -1 && a >= ar[i][1] && a <= ar[i+1][0]){
            start = i+1;
            continue;
        }
        if(end == -1 && inRange(ar[i],b)){
            b = max(b,ar[i][1]);
            end = i;
            continue;
        }
        if(end == -1 && inRange(ar[i+1],b)){
            b = max(b,ar[i+1][1]);
            end = i+1;
            continue;
        }
        if(b >= ar[i][1] && b <= ar[i+1][0]){
            end = i;
            continue;
        }
    for(int i=0;i<ar.size();++i){
        if(i == start){
            i = end;
            cout<<a<<" "<<b<<endl;
            continue;
        }
        cout<<ar[i][0]<<" "<<ar[i][1]<<endl;
    }
    // cout<<a<<" "<<b<<endl;
    return 0;
}