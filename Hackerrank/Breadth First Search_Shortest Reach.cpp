#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void BFS(vector<vector<int>> &matrix,vector<bool> &visit,int s,vector<int> &cost){
    if(visit[s]) return;
    if(matrix[s].size() == 0) {
        return;
    } 
    visit[s]=true;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int n:matrix[t])
            if(!visit[n]){
                visit[n] = true;
                q.push(n);
                if(cost[n] == 0)
                cost[n] = cost[t]+6;
            }
    }
}

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> matrix, int s,vector<bool> &visit) {
    vector<int> cost(n,0);
    BFS(matrix,visit,s-1,cost);
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);
        
        vector<vector<int>> matrix(n);
        vector<bool> visit(n);
        for(int i=0;i<n;i++){
            matrix[i] = vector<int>();
            visit[i] = false;
        }
        int e1,e2;
        for (int i = 0; i < m; i++) {
            cin>>e1>>e2;
            matrix[e1-1].push_back(e2-1);
            matrix[e2-1].push_back(e1-1);            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, matrix, s,visit);

        for (int i = 0; i < result.size(); i++) {
            if(i != s-1){
                if(result[i] == 0) fout<<-1;
                else fout << result[i];
                if (i != result.size() - 1) 
                    fout << " ";
            }
        }

        fout << "\n";
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
