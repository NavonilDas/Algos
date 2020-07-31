class Solution {
public:
    int brokenCalc(int X, int Y) {
        int c = 0;
        // Till y <= X
        while(Y > X){
            // If y is not divisible by 2 then increment by 1 and add one operation
            if(Y&1){
                ++Y;
                ++c;
            }
            // Divide Y by 2 and increase one operation
            Y /= 2;
            ++c;
        }
        // if y and x are equal then return no of operations
        // otherwise y < x no of operations done so far + difference of X - Y => we have to increment Y by this to make equal
        return (Y == X)? c :(c + X - Y);
    }
};