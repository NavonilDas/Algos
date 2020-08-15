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
    TreeNode* helper(int s,int e,vector<int> &nums){
        if(s > e) return NULL;
        int mx = s;
        for(int i=s;i<=e;++i){
            if(nums[mx] < nums[i]) mx = i;
        }
        TreeNode* x = new TreeNode(nums[mx]);
        x->left = helper(s,mx-1,nums);
        x->right = helper(mx+1,e,nums);
        return x;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // heap
        return helper(0,nums.size()-1,nums);
    }
};