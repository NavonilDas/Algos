class Solution {
public:

    int maximumSwap(int num) {
        vector<int> dig;
        while(num > 0){
            dig.push_back(num%10);
            num /= 10;    
        }
        const int n = dig.size();
        for(int i=0;2*i<dig.size();++i)
            swap(dig[i],dig[n-i-1]);
        // for(int i:dig){
        //     cout<<i<<endl;
        // }
        int pos[10];
        memset(pos,-1,sizeof(pos));
        for(int i=0;i<dig.size();++i){
            pos[dig[i]] = i;
        }
        
        bool s = false;
        for(int i=0;i<n;++i){
            for(int j=9;j>dig[i];--j){
                if(pos[j] > i){
                    swap(dig[i],dig[pos[j]]);
                    s = true;
                    break;
                }
            }
            if(s) break;
        }
        // for(int i:dig){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int ans = 0;
        for(int i = 0;i<n;++i){
            ans = ans*10 + dig[i]; 
        }
        return ans;
    }
};