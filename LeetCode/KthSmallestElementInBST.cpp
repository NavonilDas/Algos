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
#define INF (1e9+5)
class Solution {
public:
    // Does Inorder Traversal and finds the kth item
    int helper(TreeNode* root, int &k,int &i){
        if(root == NULL) return INF;
        // LEft
        int v = helper(root->left,k,i);
        if(v != INF){
            return v;
        }
        // Root
        ++i;
        if(i == k){
            return root->val;
        }
        // Right
        v = helper(root->right,k,i);
        return v;
    }
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return helper(root,k,i);
    }
};