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
public:
    int count = 0;
    int averageOfSubtree(TreeNode* root) {
        
        auto p = avg(root);

        return count;      
    }
    
    pair<int,int> avg(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }

        pair<int,int> left = avg(root->left);
        pair<int,int> right = avg(root->right);

        int sum = left.first + right.first + root->val;
        int n = left.second + right.second + 1;

        if(sum/n == root->val){
            count++;
        }

        return {sum,n};
    }
};