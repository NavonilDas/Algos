class Solution {
public:
    char findKthBit(int n, int k) {
        // if n is 1 the only posibile string is '0'
        if(n == 1) return '0';
        
        // the length of string for some value of n
        int len = (1 << n) - 1;
        // Calculate mid
        int mid = len >> 1;
        // if k is the middle element then it is 1
        if(k - 1 == mid) return '1';
        // if k is less than the mid then find for small values of n
        if(k-1 < mid) return findKthBit(n-1,k);
        // othere wise find the reversed position and invert the answer
        // reverse position for example 1 2 3 4 5 is the array
        // on reversing 5 4 3 2 1 the position of 2 in the
        // first array is 1
        // on second array is 3
        // ie. the reversed position is (n - 1) - position of 2 in first array

        // in our case we have to find the position of k-1
        return findKthBit(n-1,len - k + 1)=='0'?'1':'0';
    }
};