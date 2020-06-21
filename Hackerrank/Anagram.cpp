#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    int l = s.size();
    if(l%2) return -1;
    int h[26]={0},hs[26]={0};
    for(int i=0;i<l/2;i++){
        h[s[i] - 'a']++;
        hs[s[l/2+i] - 'a']++;
    }
    int c = 0;
    for(int i=0;i<26;i++)
        if(h!=0 && h[i] < hs[i]) c+= abs(hs[i]-h[i]);
    return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
