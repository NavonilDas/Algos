#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<string> split_string(string);

ll noofcalls;
int DFS(vector<vector<ll>> &matrix,ll k,vector<bool> &visited){
    if(visited[k]) return 0;
    noofcalls++;
    if(matrix[k].size() == 0) return 1;
    visited[k] = true;
    for(int n:matrix[k])
        if(!visited[n])
            DFS(matrix,n,visited);
    return 1;
}

// Complete the journeyToMoon function below.
ll journeyToMoon(ll n, vector<vector<ll>> astronaut,vector<bool> &visited) {
    noofcalls = 0;
    vector<ll> nodes;
    for(ll i=0;i<n;i++)
        if(DFS(astronaut,i,visited)){
            nodes.push_back(noofcalls);
            noofcalls = 0;
        }
    ll sum=0,result =0;
    for(ll x:nodes)
    {  
        result += sum*x;
        sum+=x;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    ll n = stoi(np[0]);

    ll p = stoi(np[1]);

    vector<vector<ll>> astronaut(n);
    vector<bool> visited(n);
    for(ll i=0;i<n;i++){
        astronaut[i] = vector<ll>();
        visited[i] = false;
    }

    ll p1,p2;
    for (ll i = 0; i < p; i++) {
        cin>>p1;
        cin>>p2;
        astronaut[p1].push_back(p2);
        astronaut[p2].push_back(p1);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ll result = journeyToMoon(n, astronaut,visited);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
