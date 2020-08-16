class Solution {
public:
    bool isSame(vector<int> &dig,long long x){
        vector<int> my(10,0);
        while(x > 0){
            ++my[x%10];
            x /= 10;
        }
        for(int i=0;i<10;++i) if(my[i] != dig[i]) return false;
        return true;
    }
    bool reorderedPowerOf2(int N) {
        /**
        Given a number Reorder digits such that the resultant number is in power of two and 0 is not in front
        Logic is For each power of 2 check if number of digits are same in both of them.
        **/
        vector<int> dig(10,0);
        while(N > 0){
            ++dig[N%10];
            N /= 10;
        }
        
        long long x;
        for(int i=0;i<32;++i){
            if(isSame(dig,(1 << i))) return true;
        }
        return false;
    }
};