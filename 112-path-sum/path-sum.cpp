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
    void dfs(TreeNode* root,bool &found,int sum,int target){
        if(root == NULL || found){
            return;
        }

        sum += root->val;

        if(root->left == NULL && root->right == NULL){
            found = (sum == target);
            return;
        }

        dfs(root->left,found,sum,target);
        dfs(root->right,found,sum,target);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }

        bool found = false;

        dfs(root,found,0,targetSum);

        return found;
    }
};