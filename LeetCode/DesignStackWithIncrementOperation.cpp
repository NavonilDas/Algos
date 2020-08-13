class CustomStack {
public:
    vector<int> st;
    vector<int> inc;
    int N;
    int c = 0;
    CustomStack(int maxSize) {
        N = maxSize;
    }
    
    void push(int x) {
        if(st.size() >= N) return;
        st.push_back(x);
        inc.push_back(0);
    }
    
    int pop() {
        int i = st.size() - 1;
        if(i < 0) return -1;
        if(i > 0) inc[i-1] += inc[i];
        int ans = st.back() + inc.back();
        st.pop_back();
        inc.pop_back();
        return ans;
    }
    
    void increment(int k, int val) {
        int to = min(k,(int)st.size()) - 1;
        if(to >= 0) inc[to] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */