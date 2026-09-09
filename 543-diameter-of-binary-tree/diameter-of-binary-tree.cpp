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
    pair<int,int> fastDiameter(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }

        pair<int,int> op1 = fastDiameter(root->left);
        pair<int,int> op2 = fastDiameter(root->right);

        int op3 = op1.second + op2.second + 1;

        int dia = max(op1.first, max(op2.first, op3) );

        int height = max(op1.second , op2.second) + 1;  

        return {dia,height};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        return fastDiameter(root).first - 1;
    }
};