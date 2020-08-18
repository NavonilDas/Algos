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
    void helper(TreeNode *root,int sum,int &target,vector<int> &tmp,vector<vector<int>> &ans){
        if(root == NULL) return;
        tmp.push_back(root->val);
        sum += root->val;
        if(root->left == NULL and root->right == NULL){
            // leaf
            if(sum == target){
                ans.push_back(tmp);
            }
            tmp.pop_back();
            return;
        }
        helper(root->left,sum,target,tmp,ans);
        helper(root->right,sum,target,tmp,ans);
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmp;
        vector<vector<int>> ans;
        helper(root,0,sum,tmp,ans);
        return ans;
    }
};