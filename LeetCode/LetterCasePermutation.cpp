class Solution {
public:
    void backtrack(string &s,int start,vector<string> &ans){
        if(start >= s.size()) return;
        
        for(int i=start;i<s.size();++i){
            if(s[i] >='a' && s[i] <= 'z'){
                s[i] -= 32;
                ans.push_back(s);
                backtrack(s,i+1,ans);
                s[i] += 32;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] += 32;
                ans.push_back(s);
                backtrack(s,i+1,ans);
                s[i] -= 32;
            }
        }
        
        
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        ans.push_back(S);
        backtrack(S,0,ans);
        return ans;
    }
};