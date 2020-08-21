class Solution {
public:
    bool isValid(string &S) {
        stack<char> st;
        for(char &c:S){
            if(c == 'c'){
                if(st.size() < 2) return false;
                char b = st.top();st.pop();
                char a = st.top();st.pop();
                if(b == 'b' && a == 'a') continue;
                return false;
            }else st.push(c);
        }
        return st.size() == 0;
    }
};