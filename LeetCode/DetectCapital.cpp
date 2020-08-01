class Solution {
public:
    bool detectCapitalUse(string word) {
        const int n = word.size();
        int l = 0,cp = 0;
        
        for(char &c:word){
            if(islower(c)){
                ++l;
            }else ++cp;
        }
        // cout<<word<<" "<<n<<" "<<l<<" "<<cp<<endl;
        if(n == l || n == cp) return true;
        if(isupper(word[0]) && l+1 == n) 
            return true;
        return false;
    }
};