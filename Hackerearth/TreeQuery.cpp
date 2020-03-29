#include <bits/stdc++.h>
using namespace std;

#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define ll long long
#define endl '\n'
#define ull long long
#define vi vector<int>
#define mat vector<vector<int>> 
/// Still Trying :(
// TODO: LAZY PROPOGATION

void buildTree(mat &adj,mat &tree,vector<bool> &visited,int i){
    visited[i] = true;
    for(int ne:adj[i]){
        if(!visited[ne]){
            visited[ne] = true;
            tree[i].push_back(ne);
            buildTree(adj,tree,visited,ne);
        }
    }
}

void printLeaf(mat &tree,int i,vi &seg,vi &parent){
    if(tree[i].size() == 0){
        seg[i] = 1;
    }
    else{
        seg[i] = 1;
        for(int ne:tree[i]){
            parent[ne] = i;
            printLeaf(tree,ne,seg,parent);
            seg[i] += seg[ne];
        }
    }
}

void update(int i,vi &parent,vi &seg,mat &tree){
    if(seg[i] == 0){
        seg[i] = 1;
        for(int ne:tree[i]){
            seg[i] += seg[ne];
        }
    }else
        seg[i] = 0;
    
    int p = parent[i];
    while(p != -1){
        if(seg[p] == 0) return;
        seg[p] = 1;
        for(int ne:tree[p]){
            seg[p] += seg[ne];
        }
        p = parent[p];
    }
}

int main()
{
    FASTIO;
    #ifdef OFFLINE_EXE
    freopen("input.txt","r",stdin);
    #endif
    int n,q;    
    cin>>n>>q;
    mat adj(n);
    int a,b;
    for(int i=0;i<n-1;++i){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);       
    }
    mat tree(n);
    vi seg(n,0);
    vi parent(n);

    vector<bool> visited(n);
    buildTree(adj,tree,visited,0);
    adj.clear();
    visited.clear();

    parent[0] = -1;
    printLeaf(tree,0,seg,parent);
    short typ;
    int node;
    while(q--){
        cin>>typ>>node;
        if(typ == 2)
            cout<<seg[node-1]<<endl;
        else{
            update(node-1,parent,seg,tree);
            // for(int i:seg)
                // cout<<i<<" ";
            // cout<<endl;
        }
    }
    // for(int i=0;i<n;++i)
    //     cout<<parent[i]<<endl;

    return 0;
}