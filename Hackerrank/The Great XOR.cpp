#include <bits/stdc++.h>

using namespace std;

// Complete the theGreatXor function below.
long theGreatXor(long x) {
    long r = 0,b=0;
    while(x){
         // check if it is a zero bit
        if(!(x&1))
            r += 1l<<b;
        b++;
        x = x>>1; // x/=2;
    }
    return r;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long x;
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = theGreatXor(x);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
