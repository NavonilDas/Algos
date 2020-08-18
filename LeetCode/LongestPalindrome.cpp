class Solution {
public:
    int longestPalindrome(string s) {
        int hsh[257];
        memset(hsh,0,sizeof(hsh));
        for(char &c:s){
            ++hsh[c];
        }
        int ans = 0;
        for(int i=0;i<257;++i){
            if(hsh[i] != 0){
                int x = hsh[i] / 2;
                if(x != 0){
                    ans += (x*2);
                    hsh[i] %= 2;
                }
            }
        }
        
        for(int i=0;i<257;++i){
            if(hsh[i] != 0){
                cout<<hsh[i]<<endl;
                ans += hsh[i];
                break;
            }
        }        
        
        return ans;
    }
};