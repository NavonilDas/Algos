class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j = 0;
        const int n = pushed.size();
        stack<int> st;
        while(j < n){
            if(st.empty()) {
                if(i < n)
                    st.push(pushed[i++]);
                else return false;
            }
            else{
                // cout<<st.top()<<" "<<popped[j]<<endl;
                if(st.top() == popped[j]){
                    st.pop();
                    ++j;
                }else{
                    if(i < n)
                        st.push(pushed[i++]);
                    else return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};