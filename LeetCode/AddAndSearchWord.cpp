class WordDictionary {
private:
    struct Node{
        string data;
        Node* child[27];
    };
    Node* root;
public:
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node;
        for(int i=0;i<27;++i)
            root->child[i] = NULL;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *tmp = root;
        // cout<<"ADD :  "<<word<<endl;
        for(char &c:word){
            if(tmp->child[c - 'a'] == NULL){
                tmp->child[c - 'a'] = new Node;
            for(int i=0;i<27;++i)
                tmp->child[c - 'a']->child[i] = NULL;                
            }
            tmp = tmp->child[c - 'a'];
        }
        tmp->data = word;
    }
    bool cmp(string &a,string &b){
        if(a.size() != b.size())
            return false;
        for(int i=0;i<a.size();++i){
            // cout<<"-> "<<b[i]<<" "<<a[i]<<endl;
            if(b[i] != '.' && a[i] != b[i]) return false;
        }
        return true;
    }
    bool dfs(string &word,int c,Node *tmp){
        if(c >= word.size()) {
            if(tmp != NULL){
                bool z = cmp(tmp->data,word);
                // cout<<tmp->data<<" "<<word<<" "<<z<<endl;
                if(z)
                    return true;            
                return false;
            }
            return false;
        }
        
        if(tmp == NULL) return false;
        
        if(word[c] == '.'){
            for(int i=0;i<26;++i){
                bool t = dfs(word,c+1,tmp->child[i]);
                if(t) return true;
            }
            // bool xx = dfs(word,c+1,tmp);
        }else{
            if(tmp->child[word[c] - 'a'] == NULL) return false;
            return dfs(word,c+1,tmp->child[word[c]-'a']);
        }
        return false;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        // cout<<"Search : "<<word<<endl;
        if(word.size() == 0) return false;
        Node *tmp = root;
        return dfs(word,0,tmp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */