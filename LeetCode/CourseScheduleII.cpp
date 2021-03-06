class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        // Total number of Edges
        const int nEd = prerequisites.size();
        
        // Store the count of incoming edges
        vector<int> edges(numCourses,0);
        // Adjacency list
        vector<vector<int>> graph(numCourses);
        
        // Connect the graph and increase the incoming edges
        for(auto e:prerequisites){
            ++edges[e[0]];
            graph[e[1]].push_back(e[0]);
            
        }
        // Store the to be visiting queue
        queue<int> pros;
        // Add all nodes to queue whose doesn't have incoming edge
        for(int i=0;i<numCourses;++i){
            if(edges[i] == 0){
                pros.push(i);
            }
        }
        // All edges in the graph
        int ed = nEd;
        // While Queue is not empty pop an item from queue
        // for each child of the node
        // remove the edge between node and child
        // if the incoming edge of child is zero then add it to the queue
        while(!pros.empty()){
            int t = pros.front();
            pros.pop();
            ans.push_back(t);
            for(int child:graph[t]){
                --edges[child];
                --ed;
                if(edges[child] == 0){
                    pros.push(child);
                }
            }
        }
        if(ed!=0) return {};
        return ans;
    }
};