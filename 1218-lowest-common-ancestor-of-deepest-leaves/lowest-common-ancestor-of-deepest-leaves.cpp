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
    int maxD = 0;

    void depth(TreeNode* root,auto &mp,int h){
        if(root == NULL){
            return;
        }

        maxD = max(maxD,h);
        mp[root->val] = h;

        depth(root->left,mp,h+1);
        depth(root->right,mp,h+1);
    }

    TreeNode* lca(TreeNode* root,auto &mp){
        if(root == NULL || mp[root->val] == maxD){
            return root;
        }

        TreeNode* left = lca(root->left,mp);
        TreeNode* right = lca(root->right,mp);

        if(left && right){
            return root;
        }

        if(left) return left;

        return right;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        unordered_map<int,int> mp;

        depth(root,mp,0);

        return lca(root,mp);
    }
};