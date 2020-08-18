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
    void helper(TreeNode* root,vector<int> &tmp,int &ans){
        if(root == NULL) return;
        tmp.push_back(root->val);
        if(root->left == NULL and root->right == NULL){
            int ok = 0;
            for(int &i:tmp) ok = ok*10 + i;
            // cout<<ok<<endl;   
            ans += ok;
            // cout<<ans<<endl;
        }
        helper(root->left,tmp,ans);
        helper(root->right,tmp,ans);
        tmp.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        vector<int> tmp;
        helper(root,tmp,ans);
        return ans;
    }
};