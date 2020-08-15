class DisjointSet
{
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int N)
    {
        parent = vector<int>(N);
        rank = vector<int>(N, 0);
        for (int i = 0; i < N; ++i)
            parent[i] = i;
    }
    // DisjointSet(vector<T> &Ar){

    // }
    void debug(){
        for(int i:parent){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int root(int i)
    {
        while (parent[i] != i)
        {
            i = parent[i];
        }
        return i;
    }
    void Union(int i, int j)
    {
        int ri = root(i);
        int rj = root(j);
        if (ri == rj)
            return;
        if (rank[ri] < rank[rj])
        {
            parent[ri] = rj;
        }
        else if (rank[ri] > rank[rj])
        {
            parent[rj] = ri;
        }
        else
        {
            parent[rj] = ri;
            rank[ri] = rank[ri] + 1;
        }
    }
    bool find(int i, int j)
    {
        return (root(i) == root(j));
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        map<int,vector<int>> sameRows;
        map<int,vector<int>> sameCols;
        const int n = stones.size();
        DisjointSet ds(n);
        
        for(int i=0;i<n;++i){
            sameRows[stones[i][0]].push_back(i);
            sameCols[stones[i][1]].push_back(i);            
        }
        
        for(auto row:sameRows){
            int x = row.second[0];
            for(int i:row.second){
                // cout<<x<<" "<<i<<endl;
                ds.Union(x,i);
            }
        }
        sameRows.clear();
        // cout<<endl;        
        for(auto col:sameCols){
            int x = col.second[0];
            for(int i:col.second){
                // cout<<x<<" "<<i<<endl;
                ds.Union(x,i);
            }            
        }
        sameCols.clear();
        map<int,int> crap;
        for(int i=0;i<n;++i){
            ++crap[ds.root(i)];
        }
        // cout<<crap.size()<<endl;
        // ds.debug();
        
        return n - crap.size();
    }
};