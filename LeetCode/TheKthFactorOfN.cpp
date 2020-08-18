class Solution {
public:
    
    int kthFactor(int n, int k) {
        vector<int> x;
        vector<int> y;
        --k;
        for(int i=1;i*i<=n;++i){
            if(n%i == 0){
                if(n/i == i) x.push_back(i);
                else{
                    x.push_back(i);
                    y.push_back(n/i);
                }
            }
        }
        if(k < x.size()) return x[k];
        k -= x.size();
        // cout<<"######## "<<k<<endl;
        // reverse
        k = y.size() - 1 - k;
        if(k < 0) return -1;
        // for(int n:x) cout<<n<<endl;
        // cout<<"######## "<<k<<endl;
        // for(int n:y) cout<<n<<endl;
        
        return y[k];
    }
};