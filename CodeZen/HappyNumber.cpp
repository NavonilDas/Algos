#include<bits/stdc++.h>
using namespace std;
int SS(int n){
    int rem,sum = 0;
    while(n > 0){
        rem = n%10;
        sum += rem*rem;
        n /= 10;
    }
    return sum;
}

int main() {
	int n;
    cin>>n;
    int s,f;
    s = f = n;
    do{
        s = SS(s);
        f = SS(SS(f));
    }while(s != f);
    if(s == 1)
        cout<<"true\n";
        else cout<<"false\n";
    return 0;
	// Write your code here
}