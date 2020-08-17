class Solution {
public:
    struct State{
        bool isChar;
        int val;
    };
    
    int scoreOfParentheses(string S) {
        stack<State> st;
        for(int i=0;i<S.size();++i){
            if(S[i] == '('){
                State tmp;
                tmp.isChar = true;
                tmp.val = -1;
                st.push(tmp);
            }else if(S[i] == ')'){
                int x = 0;
                while(!st.empty()){
                    State tp = st.top();
                    st.pop();
                    if(tp.isChar){
                        if(x == 0) x = 1;
                        else x = 2*x;
                        State tmp = {false,x};
                        st.push(tmp);
                        break;
                    }else x += tp.val;
                }
            }
        }
        // cout<<st.size()<<endl;
        int ans = 0;
        while(!st.empty()){
            State tp = st.top();
            st.pop();
            if(!tp.isChar)
                ans += tp.val;
        }
        // if(!st.empty()) return st.top().val;
        return ans;
    }
};