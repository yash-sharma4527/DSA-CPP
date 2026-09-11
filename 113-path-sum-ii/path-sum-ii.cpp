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
    void dfs(TreeNode* root,vector<vector<int>> &ans,vector<int> &v,int sum,int target){
        if(root == NULL){
            return;
        }

        sum += root->val;
        v.push_back(root->val);

        if(root->left == NULL && root->right == NULL){
            if(sum == target){
                ans.push_back(v);
            }
        }

        dfs(root->left,ans,v,sum,target);
        dfs(root->right,ans,v,sum,target);

        v.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;

        if(root == NULL){
            return ans;
        }

        dfs(root,ans,v,0,targetSum);

        return ans;

    }
};