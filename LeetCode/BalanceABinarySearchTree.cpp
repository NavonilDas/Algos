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
    void InOrder(TreeNode* root,vector<int> &s){
        if(root == NULL) return;
        InOrder(root->left,s);
        s.push_back(root->val);
        InOrder(root->right,s);
    }
    TreeNode* solve(vector<int> &tmp,int s,int e){
        if(s > e) return NULL;
        int m = (s+e) >> 1;
        TreeNode* x = new TreeNode(tmp[m]);
        x->left = solve(tmp,s,m-1);
        x->right = solve(tmp,m+1,e);
        return x;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> s;
        InOrder(root,s);
        return solve(s,0,s.size()-1);
    }
};