class Solution {
public:
    // Store Precomputed Factorials
    const vector<int> fac = {1, 1,2,6,24,120,720,5040,40320,362880};
    // Store already computed strings
    unordered_set<string> All;
    
    int uniquePerm(string &tiles){
        // We know that For a Word of size n
        // the number of unique permutations are n! / (m[1]! * m[2]! ....   m[k]!)
        // where m[i] represent the count of the charecter ie. how many times the word is repeated
        // Store the count of each charecter
        int hsh[27] = {0};
        for(char &c:tiles) ++hsh[c - 'A'];
        // Calculate the Factorial
        int ans = fac[tiles.size()];
        for(int m:hsh) ans /= fac[m];
        
        return ans;        
    }
    
    int dfs(int i,string &tiles,string tmp){
        
        if(i >= tiles.size()){
            auto x = All.find(tmp);
            // if the string already computed then don't add its permutation
            if(x != All.end())    return 0;
            
            // insert the string as it is calculated
            All.insert(tmp);
            // return the count of all unique permutation of tmp
            return uniquePerm(tmp);
        }
        // Either include or not include the current charecter
        return dfs(i+1,tiles,tmp) + dfs(i+1,tiles,tmp+tiles[i]);
    }
    
    int numTilePossibilities(string tiles) {
        // The Logic is for each subseqence inside the string
        // Calculate the Permutation and add it to the answer
        // Remeber we have to maintain the uniquence of the subseqence 
        // and the other subseqence should not be the permutation of the current subseqence
        
        
        // Sort Charecters as we are only intrested in permutaions
        // We need sort because lets consider the case CDC
        // we can get subsequence CD and DC if we don't sort which are permutation of each other
        sort(tiles.begin(),tiles.end());
        
        // -1 as empty string is also considered
        return dfs(0,tiles,"") - 1;
    }
};