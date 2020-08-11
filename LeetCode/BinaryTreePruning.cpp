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
    bool prune(TreeNode* root){
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL &&  root->val != 1){
            // cout<<"Deleting "<<root->val<<endl;
            // root = NULL;
            return true;
        }
        bool tmp = prune(root->left);
        if(tmp) root->left = NULL;
        bool tmp1 = prune(root->right);
        if(tmp1) root->right = NULL;
        
        if(tmp && tmp1 && root->val != 1){
            // cout<<"Deleting "<<root->val<<endl;
            // root = NULL;
            return true;
        }
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(prune(root)) return NULL;
        return root;
    }
};