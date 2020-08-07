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

#define ll long long

class Solution {
public:
    void rec(TreeNode* root,vector<int> &path,int &ans,int &target){
        if(root == NULL) return;
        path.push_back(root->val);
        rec(root->left,path,ans,target);
        rec(root->right,path,ans,target);
        ll sum = 0;
        ll t = target;
        for(int i=path.size()-1;i>=0;--i){
            sum += path[i];
            if(sum == target) {
                ++ans;
                // for(int j=i;j<path.size();++j){
                //     cout<<path[j]<<" ";
                // }
                // cout<<endl<<endl;
            }
        }        
        path.pop_back();
    }
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;   
        vector<int> path;
        rec(root,path,ans,sum);
        return ans;
    }
};