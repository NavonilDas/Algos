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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*,int>> q;
        map<int,int> hsh;
        q.push({root,0});
        while(!q.empty()){
            auto tp = q.front();
            q.pop();
            hsh[tp.second] += tp.first->val;
            if(tp.first->left){
                q.push({tp.first->left,tp.second + 1});
            }
            if(tp.first->right){
                q.push({tp.first->right,tp.second + 1});                
            }
        }
        int ans=0,mx = -1;
        for(auto &p:hsh){
            if(p.first > mx){
                mx = p.first;
                ans = p.second;
            }
        }
        return ans;
    }
};