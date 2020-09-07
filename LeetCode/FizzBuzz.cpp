class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        string a = "Fizz",b = "Buzz",c = a+b;
        for(int i=1;i<=n;++i){
            if(i%3 == 0 and i%5 ==0){
                ans.push_back(c);
            }else if(i%3 == 0){
                ans.push_back(a);
            }else if(i%5 == 0){
                ans.push_back(b);                
            }else{
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};