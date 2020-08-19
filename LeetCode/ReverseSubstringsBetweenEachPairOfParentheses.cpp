class Solution {
public:
    vector<char> buff;
    string reverseParentheses(string s) {
        stack<char> st;
        buff = vector<char>(2001);
        
        for(char &c:s){
            if(c != ')')
                st.push(c);
            else{
                int k = 0;
                while(!st.empty()){
                    char t = st.top();
                    st.pop();
                    if(t == '('){
                        for(int j=0;j<k;++j) {
                            // cout<<buff[j];
                            st.push(buff[j]);
                        }
                        break;
                    }else{
                        buff[k++] = t;
                    }
                }
                
            }
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
