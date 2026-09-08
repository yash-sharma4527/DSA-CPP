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
    pair<bool,int> heightBalance(TreeNode* root){
        if(root == NULL){
            pair<bool,int> p = {true,0};
            return p;
        }

        pair<bool,int> left = heightBalance(root->left);
        pair<bool,int> right = heightBalance(root->right);

        int height = max(left.second,right.second) + 1;

        int heightDiff = abs(left.second - right.second);

        bool bal = (left.first && right.first && heightDiff <= 1);

        return {bal,height};
    }
public:
    bool isBalanced(TreeNode* root) {

        return heightBalance(root).first;
        
    }
};