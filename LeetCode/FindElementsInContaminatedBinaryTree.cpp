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
class FindElements {
public:
    int maxSofar = 0;
    queue<TreeNode*> bfs;
    TreeNode* rooot;
    FindElements(TreeNode* root) {
        rooot = root;
        if(root == NULL) maxSofar = -1;
        else{
            // Recover
            root->val = 0;
            /*
            bfs.push(root);
            while(!bfs.empty()){
                TreeNode* r = bfs.front();
                bfs.pop();
                if(r->left){
                    r->left->val = 2*r->val + 1;
                    bfs.push(r->left);
                }
                if(r->right){
                    r->right->val = 2*r->val + 2;
                    bfs.push(r->right);
                }
            }
            */
        }
    }
    
    bool find(int target) {
        if(rooot == NULL) return false;
        int k = target + 1;        
        bool start = false;
        TreeNode *n = rooot;
        for(int i=20;i>=0;--i){
            bool bit = (k>>i)&1;
            if(!start && bit){
                start = true;
                continue;
            }
            if(start){
                if(bit) {
                    if(n == NULL) return false;
                    if(n->right) n->right->val = 2*n->val + 2;
                    n = n->right;
                }
                else{
                    if(n == NULL) return false;
                    if(n->left) n->left->val = 2*n->val + 1;
                    n = n->left;
                }
            }
        }
        if(n){
            if(n->val == target) return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */