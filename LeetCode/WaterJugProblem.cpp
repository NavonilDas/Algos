class Solution {
public:
    int gcd(int a,int b){
        return (b==0)?a:gcd(b,a%b);
    }
    
    bool canMeasureWater(int x, int y, int z) {
        /**
        The Question Becomes 
        a*x + b*y = z
        such that a and b can be negative and positive or zero
        similar to Diophantine Equations
        ***/
        if(z == 0 || x == z || y == z) return true;
        if(x + y < z) return false;
        int k = gcd(x,y);
        return z%k == 0;
    }
};