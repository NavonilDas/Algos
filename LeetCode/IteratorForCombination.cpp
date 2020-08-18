class CombinationIterator {
public:
    int all;
    int curP;
    string cur;
    string comb;
    map<char,int> pos;
    CombinationIterator(string characters, int combinationLength) {
        const int n = characters.size();
        int l = combinationLength;
        if(l > n - l)
            l = n - l;
        int tmp = 1;
        for(int i=0;i<l;++i){
            tmp *= (n-i);
            tmp /= (i+1);
        }
        int i = 0;
        for(char &c:characters){
            pos[c] = i;    
            ++i;
        }
        
        all = tmp;
        curP = 1;
        comb = characters;
        // for(int i=0;i < combinationLength)
            // cut +
        cur = characters.substr(0,combinationLength);
        // cout<<cur<<endl;
    }
    string next() {
        // TODO: Find Next permutaion
        const int n = cur.size();
        const int l = comb.size();
        string tmp = cur;
        int i = 0,j = -1;
        for(i=n-1;i>=0;--i){
            // cout<<i<<"  "<<comb[l - n + i]<<endl;
            if(cur[i] != comb[l - n + i]){
                j = i;
                break;
            }
        }

        if(j != -1){
            // cout<<cur[j]<<"  "<<pos[cur[j]]<<endl;
            cur[j] = comb[pos[cur[j]]+1];
            for(int k=j+1;k<n;++k){
                cur[k] = comb[pos[cur[k-1]]+1];
            }
            // for(int k=j;k<n;++k){
            //     cur[j] = comb[pos[cur[j]]+1];
            // }
        }
        // cout<<cur<<endl;
        // cout<<j<<endl;
        ++curP;
        return tmp;
    }
    
    bool hasNext() {
        if(curP > all) return false;
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */