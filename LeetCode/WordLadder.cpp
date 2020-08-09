class Solution {
public:

    unordered_set<string> dict; // WordList to Set for fast searching
    unordered_set<string> visited; // Stores the strings which are visited
    
    int bfs(string &start,string &end){
        // Queue to Store Current string and level        
        queue<pair<string,int>> qu;
        // insert start with level 1 and make it visited
        qu.push({start,1});
        visited.insert(start);
        
        // While queue is not empty
        while(!qu.empty()){
            auto f = qu.front();
            qu.pop();
            
            // if we found the answer return the level
            if(f.first == end) return f.second;
            
            for(int i=0;i<f.first.size();++i){
                char t = f.first[i];                
                for(int j=0;j<26;++j){
                    f.first[i] = ('a'+j);
                    // cout<<f.first<<endl;        
                    if(dict.find(f.first) != dict.end() && visited.find(f.first) == visited.end()){
                        qu.push({f.first,f.second+1});
                        visited.insert(f.first);
                    }
                }
                f.first[i] = t;
            }
        }
       return 0; 
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        dict.clear();
        visited.clear();
        if(wordList.size() == 0) return 0;
        for(string &s:wordList){
            dict.insert(s);
        }
        if(dict.find(endWord) == dict.end()) return 0;
        return bfs(beginWord,endWord);
    }
};