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
    int sum = 0;

    void total(TreeNode* root,int i){
        if(root == NULL){
            return;
        }

        if(i == 2){
            sum += root->val;
        }

        total(root->left,i+1);
        total(root->right,i+1);
    }

    void traversal(TreeNode* root){
        if(root == NULL){
            return;
        }

        if(root->val % 2 == 0){
            total(root->left,1);
            total(root->right,1);
        }

        traversal(root->left);
        traversal(root->right);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        sum = 0;

        traversal(root);

        return sum;
    }
};