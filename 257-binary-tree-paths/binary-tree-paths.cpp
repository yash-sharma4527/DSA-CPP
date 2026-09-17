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
    void dfs(TreeNode* root,string path,vector<string> &ans){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            string str = to_string(root->val);
            path.append(str);
            ans.push_back(path);
            return;
        }

        string str = to_string(root->val);
        str.append("->");
        path.append(str);

        dfs(root->left,path,ans);
        dfs(root->right,path,ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        string path;

        dfs(root,path,ans);

        return ans;
    }
};