class Solution {
public:
    string customSortString(string S, string T) {
        map<char,bool> hsh;
        map<char,int> hsh2;
        for(char &c:S){
            hsh[c] = true;
        }
        for(char &c:T){
            ++hsh2[c];
        }
        
        string ans = "";
        for(char &c:S){
            if(hsh2[c]) {
                while(hsh2[c] > 0){
                    ans+=c;
                    --hsh2[c];
                }
            }
        }
        for(char &c:T){
            // hsh2[c] = true;
            if(hsh2[c] > 0) {
                ans+=c;
                --hsh2[c];
            }
        }

        return ans;
    }
};