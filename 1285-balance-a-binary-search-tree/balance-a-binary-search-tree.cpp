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
    void inorder(TreeNode* root,vector<int> &nodes){
        if(root == NULL){
            return;
        }

        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    }

    TreeNode* solve(vector<int> &nums,int s,int e){
        if(s > e){
            return NULL;
        }

        int mid = s + (e-s)/2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = solve(nums,s,mid-1);
        root->right = solve(nums,mid+1,e);

        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;

        inorder(root,nodes);

        return solve(nodes,0,nodes.size()-1);
    }
};