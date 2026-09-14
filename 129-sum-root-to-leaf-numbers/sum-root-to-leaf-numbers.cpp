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
    void dfs(TreeNode* root, int sum, int &ans){
        if(root == NULL){
            return;
        }

        sum = sum*10 + root->val;

        if(root->left == NULL && root->right == NULL){
            ans += sum;
            return;
        }

        dfs(root->left,sum,ans);
        dfs(root->right,sum,ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        
        int ans = 0;
        int sum = 0;

        dfs(root,sum,ans);

        return ans;
        
    }
};