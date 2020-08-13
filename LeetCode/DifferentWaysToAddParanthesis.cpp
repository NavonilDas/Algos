class Solution {
public:
    vector<int> solve(int start,int e,string &s){
        if(start > e) return {};
        vector<int> tmp;
        bool noOp = true;
        string z = "";
        for(int i=start;i<=e;++i){
            if(s[i] == '+'){
                vector<int> a = solve(start,i-1,s);
                vector<int> b = solve(i+1,e,s);
                for(int x:a){
                    for(int y:b){
                        tmp.push_back(x + y);
                    }
                }
                noOp = false;
            }else if(s[i] == '*'){
                vector<int> a = solve(start,i-1,s);
                vector<int> b = solve(i+1,e,s);
                for(int x:a){
                    for(int y:b){
                        tmp.push_back(x * y);
                    }
                }
                noOp = false;
            }else if(s[i] == '-'){
                vector<int> a = solve(start,i-1,s);
                vector<int> b = solve(i+1,e,s);
                for(int x:a){
                    for(int y:b){
                        tmp.push_back(x - y);
                    }
                }
                noOp = false;
            }else{
                z+=s[i];                
            }
        }
        if(noOp){
            // cout<<z<<endl;
            tmp.push_back(stoi(z));
        }
        return tmp;
    }
    vector<int> diffWaysToCompute(string input) {
        // vector<int> ans;
        return solve(0,input.size()-1,input);
        // return ans;
    }
};