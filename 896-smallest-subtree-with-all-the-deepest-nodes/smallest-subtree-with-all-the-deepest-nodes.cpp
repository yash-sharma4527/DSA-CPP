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
      pair<int,TreeNode*> lca(TreeNode* root){
        if(root == NULL){
            return {0,NULL};
        }

        auto left = lca(root->left);
        auto right = lca(root->right);

        if(left.first == right.first){
            return {left.first+1,root};
        }

        if(left.first > right.first){
            return {left.first+1,left.second};
        }

        else{
            return {right.first + 1 , right.second};
        }
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        return lca(root).second;
        
    }
};