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
    void helper(TreeNode *root,int &ans){
        if(root == NULL) return;
        if(!(root->val&1)){
            // left child left grandchild
            if(root->left && root->left->left)
                ans += root->left->left->val;
            // left child right grandchild            
            if(root->left && root->left->right)
                ans += root->left->right->val;
            // right child left grandchild            
            if(root->right && root->right->left)
                ans += root->right->left->val;
            // right child right grandchild            
            if(root->right && root->right->right)
                ans += root->right->right->val;
        }
        helper(root->left,ans);
        helper(root->right,ans);        
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        helper(root,ans);
        return ans;
    }
};