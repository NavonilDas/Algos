class Solution {
public:
    int minInsertions(string &s) {
        int ans = 0;
        int clo = 0;
        stack<char> st;
        // string tmp;
        for(char c:s){
            // tmp += c;
            if(c == '('){
                if(clo  == 1){
                    ++ans; // Add A Closing Bracket
                    if(st.empty()) {
                        ++ans;
                    }
                    else st.pop();
                    
                }
                clo = 0;
                st.push('(');
            }
            
            if(c == ')'){
                ++clo;  
                if(clo == 2){
                    if(st.empty()) ++ans;
                    else st.pop();
                    clo = 0;
                }
            }
            // cout<<tmp<<" "<<ans<<endl;
        }
        
        if(clo  == 1){
            ++ans;
            if(st.empty()) ++ans;
            else st.pop();
        }
        if(clo >= 2) {
            assert(false);
        }
        ans += 2*st.size();
        cout<<ans<<endl;
        return ans;
    }
};