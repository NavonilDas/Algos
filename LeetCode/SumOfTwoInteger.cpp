class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        while(b != 0){
            // "& 0x7fffffff" Just because the compiler in Leetcode does not allow left shift when the first bit is 1.
            carry = a & b & 0x7fffffff; // Calculate Carry
            a = a^b; // Calculate the sum
            b = carry << 1; // B becomes new Carry
        }
        return a;
    }
};