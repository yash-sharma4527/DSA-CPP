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
    void inorder(TreeNode* root,vector<int> &vec){
        if(root == NULL){
            return;
        }

        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;

        inorder(root1,tree1);
        inorder(root2,tree2);

        int m = tree1.size();
        int n = tree2.size();

        vector<int> ans(m+n);

        int i = 0;
        int j = 0;
        int k = 0;

        while(i<m && j<n){
            if(tree1[i]<tree2[j]){
                ans[k++] = tree1[i++];
            }
            else{
                ans[k++] = tree2[j++];
             }
         }

        
            while(i<m){
                ans[k++] = tree1[i++];
            }
        
            while(j<n){
                ans[k++] = tree2[j++];
            }
        

        return ans;
    }
};