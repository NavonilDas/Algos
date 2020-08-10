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
    TreeNode* helper(int s,int e,vector<int>& nums){
        if(s > e) return NULL;
        int mid = (s+e) >> 1;
        // cout<<s<<" "<<e<<" "<<mid <<endl;
        TreeNode *tree = new TreeNode(nums[mid]);
        tree->left = helper(s,mid-1,nums);
        tree->right = helper(mid+1,e,nums);
        return tree;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        return helper(0,nums.size()-1,nums);
    }
};