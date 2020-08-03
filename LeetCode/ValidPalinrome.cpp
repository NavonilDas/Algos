class Solution {
public:

    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        if(s.size() == 1) return true;
        if(s.size() == 2){
            if(isalnum(s[0]) && isalnum(s[1]))
               return tolower(s[0]) == tolower(s[1]);
              return true;
        }
        int l = 0,r = s.size()-1;
        bool flag = true;
        
        while(l < r){
            if(!isalnum(s[l])) {
                ++l;
                continue;
            }
            if(!isalnum(s[r])){
                --r;
                continue;
            }
            // cout<<s[l]<<" "<<s[r];
            if(tolower(s[l]) == tolower(s[r])){
                // cout<<" = true\n";
                ++l;
                --r;
            }else{
                // cout<<" = false\n";
                flag = false;
                break;
            }
        }
        // cout<<endl;
        return flag;
    }
};