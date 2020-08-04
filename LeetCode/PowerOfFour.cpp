class Solution {
public:
    bool isPowerOfFour(int num) {
        // We don't Consider negative numbers even though given in our constraints
        if(num < 0) return false;
        
        // Num should not be zero
        // 1 is also a power of 4 => 4^0
        // Num should be divisible by zero
        // we And with 0xAAAAAAAA bcz We have to ignore numbers which are power of 2 but not the power of 4
        // example 8 => 1000, 32 => 100000 2=> 10 or these number we get 101010 similarly for other numbers
        // finaly we get a binary number like 10101010101010...... Which is represented as 0xAAAAAAAA
        return (num !=0) && (num&(num-1)) == 0 && !(num &0xAAAAAAAA);
    }
};