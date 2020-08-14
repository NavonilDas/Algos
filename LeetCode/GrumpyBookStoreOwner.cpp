class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        const int n = customers.size();
        int notGrumpy = 0; // When the owner is not grumpy we just add it to the answer
        int whenGrumpy = 0; // When owner is grumpy we store the satification in this
        // We are given X we can convert X number of 1's to 0's
        int maxGrumpy = 0; // Store the maximum satisfaction we can get on conversion X elements
        
        for(int i=0;i<n;++i){
            if(!grumpy[i]) notGrumpy += customers[i];
            else whenGrumpy += customers[i];
            
            // If the owner stop becoming grumpy at i - X minute ago 
            // what will the satifaction then 
            if(i >= X){
                whenGrumpy -= grumpy[i - X] * customers[i - X];
            }
            
            maxGrumpy = max(whenGrumpy,maxGrumpy);
        }
        
        return notGrumpy + maxGrumpy;
    }
};