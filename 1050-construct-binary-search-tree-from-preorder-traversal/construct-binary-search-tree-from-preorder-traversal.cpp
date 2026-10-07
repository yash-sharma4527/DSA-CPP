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
    int position(auto &pre,int s,int e,int key){

        for(int i=s+1; i<=e ; i++){
            if(pre[i] > key){
                return i;
            }
        }

        return -1;
    } 
    TreeNode* solve(vector<int> &pre,int s,int e){
        if(s > e){
            return NULL;
        }

        if(s==e){
            return new TreeNode(pre[s]);
        }

        TreeNode* root = new TreeNode(pre[s]);

        int pos = position(pre,s,e,pre[s]);

        if(pos == -1){
            root->left = solve(pre,s+1,e);
            root->right = NULL;
        }

        else{
            root->left = solve(pre,s+1,pos-1);
            root->right = solve(pre,pos,e);
        }

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return solve(preorder,0,preorder.size()-1);

    }
};