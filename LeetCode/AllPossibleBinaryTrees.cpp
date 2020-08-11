/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        
        if(N <= 0 or !(N&1)) return {};
        
        // 1 2 3 4 5 6 7 8 ............ i-1 i i+1 i+2 .......... N
        // if we choose i as the root then 
        // the left subtree of i is the all possible Binary trees we can make from 1 .... i-1
        // the right subtree of i is the all possible Binary trees we can make from i+1 ........ N
        
        //Below is the DP approach of solving problem
        vector<vector<TreeNode*>> dp(N+1);
        
        dp[1].push_back(new TreeNode(0)); // When there is only one node
       
        for(int numNodes = 1; numNodes <= N; numNodes += 2){
            // We increment by 2 because we can have either 0 or 2 Childrens
            // we can have 1 as Number of nodes because one will have only one node which is itself
            // we cannot have 2 bcz one of the node will taken as root and the other is the child then which will violate 0 or 2 children
            // for 3 one root two children
            // for 4 not possible
            
            for(int leftNode=1;leftNode < numNodes; leftNode += 2){
                // For each left root node which is less than the current node
                
                for(TreeNode* left:dp[leftNode]){
                    // All possible subtree where root is leftNode
                    
                    for(TreeNode* right:dp[numNodes - 1 - leftNode]){
                        // All Posiible subtree where root is N - 1 - i  ie righ subtree
                        
                        // Make the numNode as root and left child as left subtree and right child as right subtree
                        TreeNode* tmp = new TreeNode(0);
                        tmp->left = left;
                        tmp->right = right;
                        
                        // Append to our dp array
                        dp[numNodes].push_back(tmp);
                    }
                }
                
            }
        }
        
        return dp[N];
    }
};