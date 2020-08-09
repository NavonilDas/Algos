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
    int rightHeight(TreeNode* root){
        int ans = 0;
        TreeNode* tmp = root;
        while(tmp != NULL){
            tmp = tmp->right;
            ++ans;
        }
        return ans;
    }
    int leftHeight(TreeNode* root){
        int ans = 0;
        TreeNode* tmp = root;
        while(tmp != NULL){
            tmp = tmp->left;
            ++ans;
        }
        return ans;
    }
    
    int countNodes(TreeNode* root) {
        int l = leftHeight(root);
        int r = rightHeight(root);
        // if height of left subtree is equal to right sub tree then the number of nodes in tree is 2^height - 1
        if(l==r)
            return (1<<l)-1;
        else
            return 1+countNodes(root->left) + countNodes(root->right);
        // int c = 0;
        // if(root == NULL) return 0;
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     TreeNode* t = q.front();
        //     ++c;
        //     q.pop();
        //     if(t->left != NULL)
        //         q.push(t->left);
        //     if(t->right != NULL)
        //         q.push(t->right);
        // }
        // return c;
    }
};