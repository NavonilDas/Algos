#define ll long long

class Solution {
public:
    ll gcd(ll a,ll b){
	if(b == 0) return a;
	    return gcd(b,a%b);
    }
    int nthUglyNumber(int n, int A, int B, int C) {
        long a = A,
        b = B,
        c = C,
        ab = a*b / gcd(A,B),
        bc = b*c / gcd(B,C),
        ac = a*c / gcd(A,C),
        abc = a*bc / gcd(a,bc);

        // binary Search the answer
        ll l = 1,r = 2e9;
        // int ans = 0;
        while(l <= r){
            ll mid = (l+r) >> 1;
            // Principle of inclusion and exclusion
            int numbers = (mid / a) + (mid / b) + (mid / c) - (mid / ab) - (mid / bc) - (mid / ac) + (mid / abc);
            if(numbers < n){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        return l;
    }
};