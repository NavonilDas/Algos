class Solution {
public:
    int minAddToMakeValid(string &S) {
        stack<char> st;
        int ans = 0;
        for(char &c:S){
            if(c == '(') st.push('(');
            if(c == ')'){
                if(st.empty() || st.top() != '('){
                    ++ans;
                }else{
                    st.pop();
                }
            }
        }
        
        ans += st.size();
        return ans;
    }
};