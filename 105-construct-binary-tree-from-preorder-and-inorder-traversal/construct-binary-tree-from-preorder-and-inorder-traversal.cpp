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
    TreeNode* solve(vector<int> &pre,vector<int> &in,int &preIdx,int startIn,int endIn,int n,auto &mp){
        if(preIdx == n || startIn > endIn){
            return NULL;
        }

        int element = pre[preIdx++];
        TreeNode* root = new TreeNode(element);

        int pos = mp[element];

        root->left = solve(pre,in,preIdx,startIn,pos-1,n,mp);
        root->right = solve(pre,in,preIdx,pos+1,endIn,n,mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int,int> mp;

        for(int i=0; i<in.size(); i++){
            mp[in[i]] = i;
        }

        int preIdx = 0;

        return solve(pre,in,preIdx,0,in.size()-1,pre.size(),mp);
    }
};