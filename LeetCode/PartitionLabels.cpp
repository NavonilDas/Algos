class Solution {
public:
    vector<int> partitionLabels(string &S) {
        vector<int> ans;
        int pos[27];
        memset(pos,-1,sizeof(pos));
        int i = 0;
        
        // Store the last occurence of the charecter
        for(char &c:S){
            pos[c - 'a'] = i++;
        }
        // idx will store the Maximum Partition index
        // lastPos will Store the last position before partition
        int idx = 0,lastPos = 0;
        
        for(i=0;i<S.size();++i){
            // Find the maximum Last position of current charecter
            idx = max(idx,pos[S[i] - 'a']);
            
            // if the maximum position is the current position
            if(idx == i) {
                // Add the length of the substring
                ans.push_back(i - lastPos + 1);
                // Update the last position
                lastPos = i+1;
            }
            
        }
        
        return ans;
    }
};