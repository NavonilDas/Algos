/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* helper(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original == NULL) return NULL;
        if(original == target) return cloned;
        TreeNode* a = helper(original->left,cloned->left,target);
        if(a != NULL) return a;
        TreeNode* b = helper(original->right,cloned->right,target);        
        if(b != NULL) return b;
        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {   
        return helper(original,cloned,target);
    }
};