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
    void inorder(TreeNode* root,vector<TreeNode*> &vec){
        if(root == NULL){
            return;
        }

        inorder(root->left,vec);
        vec.push_back(root);
        inorder(root->right,vec);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> vec;

        inorder(root,vec);

        for(int i=0; i<vec.size()-1; i++){
            vec[i]->left = NULL;
            vec[i]->right = vec[i+1];
        }

        vec.back()->left = NULL;
        vec.back()->right = NULL;

        return vec[0];
    }
};