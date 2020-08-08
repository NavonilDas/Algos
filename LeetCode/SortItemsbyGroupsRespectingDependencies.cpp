class Solution {
public:
    /**
    Simplifying The Question
    we have a group
    and list of item
    each item can be on a group or -1 if not in a group
    
    also we have given a for a item i we have before item which means before taking item i we have to take 
    all the items in before items
    **/
    
    // DS to Store Grap
    class Graph{
        public:
            // adjacency list
            vector<vector<int>> adj;
            // in degree -> number of incoming edges
            vector<int> ind; 
            // Number of Nodes in a Graph
            int N;
            // Number of Edges in a Graph
            int E;
            // Constructor
            Graph(int n){
                N = n;
                E = 0;
                adj = vector<vector<int>>(n);
                ind = vector<int>(n,0);
            }
        
            void addEdge(int to,int from){
                adj[from].push_back(to); // Add to the list
                ++ind[to]; // Increase incoming degree
                ++E; // add edge
            }
            // For Debuging
            void printGraph(){
                for(int i=0;i<adj.size();++i){
                    cout<<i<<": ";
                    for(int j:adj[i]){
                        cout<<j<<",";
                    }
                    cout<<endl;
                }
                cout<<"Nodes "<<N<<", Edges"<<E<<endl;
            }
    };
    
    void buildGroupGraph(Graph &g,vector<int>& group, vector<vector<int>>& beforeItems){
        /**
        We know that the beforeitems needs to come before current item 
        it tells us that if the current item is on group g
        and items on beforeItems are on some different group
        that means the different group needs to come first before the current group
        **/
        for(int i=0;i<group.size();++i){
            int toGroup = group[i]; // Current Group
            
            for(int &before:beforeItems[i]){
                // Group Before the current group
                int fromGroup = group[before];
                // if they are in same group ignore
                if(toGroup == fromGroup) continue;
                // Add the edge for the graph
                g.addEdge(toGroup,fromGroup);
            }
        }
        // g.printGraph();
        
    }
    void buildItemGraph(Graph &g,int &n, vector<vector<int>>& beforeItems){
        /**
            Item Graph tells up before choosing item i we have to choose all the items in beforeItems
        */
        for(int i=0;i<n;++i){
            for(int &j:beforeItems[i]){
                g.addEdge(i,j);
            }
        }
        // g.printGraph();
    }
    // Topological sort for correct order
    vector<int> topSort(Graph &g){
        vector<int> ans;
        int edg = g.E;
        queue<int> q;
        for(int i=0;i<g.N;++i){
            if(g.ind[i] == 0){
                // cout<<i<<" ";
                q.push(i);        
            }
        }
        // cout<<endl;
        
        while(!q.empty()){
            int t = q.front();
            q.pop();
            ans.push_back(t);
            for(int child:g.adj[t]){
                --g.ind[child];
                --edg;
                if(g.ind[child] == 0){
                    q.push(child);
                }
            }
        }
        // if there is cycle return empty list
        if(edg != 0) return {};
        // other wise return complete ans
        return ans;
    }
    
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        // For those items that don belong to a group assign them a new group
        for(int &i:group){
            if(i == -1) i = m++;
        }
        
        /// Graph for groups
        Graph grpGraph(m);
        // Graph for Items
        Graph itemGraph(n);
        
        // Build the Graphs
        buildGroupGraph(grpGraph,group,beforeItems);
        buildItemGraph(itemGraph,n,beforeItems);
        
        // Do Topological sort
        vector<int> grpSort = topSort(grpGraph);
        vector<int> itemSort = topSort(itemGraph);

        // Check: Sort
        // for(int i:grpSort)
        //     cout<<i<<" ";
        // cout<<endl;
        // for(int i:itemSort)
        //     cout<<i<<" ";
        // cout<<endl;
        
        // if there is cycle then the answer is not possible
        if(grpSort.size() == 0 || itemSort.size() == 0) return {};
        
        // Store for each group all the items that belongs to the group
        vector<vector<int>> groupMapItem(m);
        
        // Foreach item in the sorted list append to their respective group
        for(int &item:itemSort){
            groupMapItem[group[item]].push_back(item);
        }
        
        vector<int> ans;
        
        // Answer is respective to the sorted group
        for(int &g:grpSort){
            for(int item:groupMapItem[g]){
                ans.push_back(item);
            }
        }
        
        return ans;
    }
};