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
    map<int,vector<pair<int,int>>> hsh;
    void helper(TreeNode* root,int x){
//         if(root == NULL) return;
//         hsh[x].push_back(root->val);
        
//         helper(root->left,x-1);
//         helper(root->right,x+1);
        queue<pair<TreeNode*,int>> q;
        queue<int> levels;
        q.push({root,0});
        levels.push(0);
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int l = levels.front();
            levels.pop();
            
            hsh[t.second].push_back({l,t.first->val});
            if(t.first->left != NULL){
                q.push({t.first->left,t.second - 1});
                levels.push(l+1);                
            }
            if(t.first->right != NULL){
                q.push({t.first->right,t.second + 1});
                levels.push(l+1);
            }
        }
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        hsh.clear();
        helper(root,0);
        vector<vector<int>> ans(hsh.size());
        // cout<<hsh.size()<<endl;
        int i = 0;
        for(auto &p:hsh){
            // cout<<p.first<<" : ";
            sort(p.second.begin(),p.second.end());
            for(pair<int,int> &j:p.second){
                // cout<<j<<",";
                ans[i].push_back(j.second);
            }
            // cout<<endl;
            ++i;
        }
        
        return ans;
    }
};