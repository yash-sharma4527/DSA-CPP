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
    void dfs(TreeNode* root,TreeNode* temp,bool &found,vector<TreeNode*> &v){
        if(root == NULL){
            return;
        }

        if(root == temp){
            v.push_back(root);
            found = true;
            return;
        }

        dfs(root->left,temp,found,v);

        if(!found){
            dfs(root->right,temp,found,v);
        }

        if(found) v.push_back(root);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> a;
        vector<TreeNode*> b;

        bool foundP = false;
        bool foundQ = false;

        dfs(root,p,foundP,a);
        dfs(root,q,foundQ,b);

        for(int i=0; i<a.size(); i++){
            for(int j=0; j<b.size(); j++){
                if(a[i]==b[j]){
                    return a[i];
                }
            }
        }

        return root;
    }
};