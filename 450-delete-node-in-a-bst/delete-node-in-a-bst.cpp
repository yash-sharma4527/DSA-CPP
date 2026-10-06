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
    int successor(TreeNode* root){
        if(root->left == NULL){
            return root->val;
        }

        return successor(root->left);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }

        if(root->val == key){
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            else if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            else if(root->right != NULL && root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            
            else{
                int next = successor(root->right);
                root->val = next;
                root->right = deleteNode(root->right,next);
                return root;
            }
        }

        else if(root->val > key){
            root->left = deleteNode(root->left,key);
            return root;
        }

        else{
            root->right = deleteNode(root->right,key);
            return root;
        }
    }
};