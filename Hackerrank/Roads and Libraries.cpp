#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<string> split_string(string);

ll noOfcalls;
int DFS(vector<vector<ll>> &matrix,ll k,vector<bool> &visited){
    if(visited[k]) return 0;
    noOfcalls++;
    if(matrix[k].size() == 0) return 1;
    visited[k] = true;
    // cout<<k<<"->";
    for(int n:matrix[k])
        if(!visited[n])
            DFS(matrix,n,visited);
    return 1;
}

ll roadsAndLibraries(ll n, ll c_lib, ll c_road, vector<vector<ll>> cities,vector<bool> &visited) {
    if(c_road > c_lib) return (n*c_lib);
    noOfcalls = 0;
    ll cost = 0;

    for(ll i=0;i<n;i++){
        if(DFS(cities,i,visited)) {
            cost += ((noOfcalls-1) < 0?0:noOfcalls-1)*c_road + c_lib;
            noOfcalls = 0;
        }
    }
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    vector<vector<ll>> matrix;
    vector<bool> visited;
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        ll n = stoi(nmC_libC_road[0]);
        matrix = vector<vector<ll>>(n);
        visited = vector<bool>(n);

        for(ll i=0;i<n;i++){
            matrix[i] = vector<ll>();
            visited[i] = false;
        }
        ll m = stoi(nmC_libC_road[1]);

        ll c_lib = stoi(nmC_libC_road[2]);

        ll c_road = stoi(nmC_libC_road[3]);

        ll c1,c2;
        for (ll i = 0; i < m; i++) {
            cin >> c1;
            cin >> c2;
            matrix[c1-1].push_back(c2-1);
            matrix[c2-1].push_back(c1-1);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        long long result = roadsAndLibraries(n, c_lib, c_road, matrix,visited);

        fout << result << "\n";
    }

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
