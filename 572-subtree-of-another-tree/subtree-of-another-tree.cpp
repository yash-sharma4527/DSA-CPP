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
    bool identical(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }

        if(root1 == NULL || root2 == NULL){
            return false;
        }

        if(root1->val != root2->val){
            return false;
        }

        bool left = identical(root1->left,root2->left);
        bool right = identical(root1->right,root2->right);

        return left && right ;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL){
            return true;
        }

        if(root == NULL || subRoot == NULL){
            return false;
        }
        
        if(identical(root,subRoot)){
            return true;
        }

        else if(isSubtree(root->left,subRoot)){
            return true;
        }

        else if(isSubtree(root->right,subRoot)){
            return true;
        }

        return false;
    }
};