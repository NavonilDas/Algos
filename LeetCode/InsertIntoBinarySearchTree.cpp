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
    void helper(TreeNode *root,int x){
        if(root == NULL) return;
        
        // if(root->left == NULL && root->right == NULL){
        //     if(root->val < x)
        //         root->right = new TreeNode(x);
        //     else root->left = new TreeNode(x);
        //     return;
        // }
        
        if(root->val < x){
            // right
            if(root->right)
                helper(root->right,x);
            else root->right = new TreeNode(x);
        }else{
            // left
            if(root->left)
                helper(root->left,x);
            else root->left = new TreeNode(x);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        helper(root,val);
        if(root == NULL) root = new TreeNode(val);
        return root;
    }
};