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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        stack<pair<int,TreeNode*> > st;
        st.push({0,root});
        map<int,int> hsh;
        
        while(!st.empty()){
            auto x = st.top();
            st.pop();
            hsh[x.first] = x.second->val;
            if(x.second->right != NULL){
                st.push({x.first + 1,x.second->right});
            }            
            if(x.second->left != NULL){
                st.push({x.first + 1,x.second->left});
            }
        }
        vector<int> ans;
        for(auto &p:hsh){
            ans.push_back(p.second);
        }
        return ans;
    }
};