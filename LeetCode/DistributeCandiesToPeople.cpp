class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        // 1 + 2 + 3 + 4 .................. some term => 10
        // Sn = 10 X
        // Sn = n*(2a+(n-1)d) / 2 => n * n+1 / 2
        // find the value of n
        // n2 + n - 2*Sn = 0
        // -1 +/- sqrt(1 + 8Sn) / 2
        // -1 +/- 9 / 2 => 4
        // 4 + 5 ... 
        // 6
        if(num_people == 1) return {candies};
        const int n = num_people;
        vector<int> ans(n,0);
        long long tmpSum = 0,cnt = 1; 
        int i = 0;
        while(true){
            ans[i] += cnt;
            tmpSum += cnt;
            if(tmpSum > candies){
                int dif = tmpSum - candies;
                ans[i] -= dif;
                break;
            }
            ++cnt;
            i = (i+1)%n;
        }
//         int r = 0;
//         int a = 1;
//         while(tmpSum < candies){
//             tmpSum += ((n * (2*a + (n-1))) >> 1);
//             a = a + num_people;
//             ++r;
//         }
//         cout<<r<<endl;
        return ans;
    }
};