class Solution {
private:
    string convert(int cnt){
        string ans = "";
        for(int i=0;i<6;++i){
            ans += subs[cnt%62];
            cnt /= 62;
        }
        return ans;
    }
    int Back(string x){
        const int n = x.size();
        // WNUjaa => 2324242
        unsigned int t = 1;
        int ans = 0;
        for(int i=0;i<n;++i){
            ans += char2Int[x[i]] * t;
            t *= 62;
        }
        // cout<<ans<<endl;
        return ans;
    }

public:
    // map<string,string> hsh;
    const string subs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int base = 62;
    int char2Int[257];
    long long counter = 0;
    vector<string> db;
    Solution(){
        // TODO: Randomize
        memset(char2Int,-1,sizeof(char2Int));
        for(int i=0;i<subs.size();++i){
            char2Int[subs[i]] = i;
        }
        // cout<<subs.size()<<endl;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string z = convert(counter++);
        db.push_back(longUrl);
        return z;
    }
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int z = Back(shortUrl); 
        if(z >= db.size()) return "";
        return db[z];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));