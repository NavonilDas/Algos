class Solution {
public:
    int minSteps(string s, string t) {
        int hsh1[27] = {0};
        int hsh2[27] = {0};
        const int n = t.size();
        for(int i=0;i<n;++i){
            ++hsh1[s[i] - 'a'];
            ++hsh2[t[i] - 'a'];
        }
        int ans= 0;
        for(int i=0;i<26;++i) ans+= abs(hsh1[i] - hsh2[i]);
        return ans>>1;
    }
};