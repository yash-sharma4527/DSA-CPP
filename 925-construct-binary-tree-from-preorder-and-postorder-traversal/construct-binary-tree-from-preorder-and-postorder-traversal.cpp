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
    TreeNode* solve(vector<int> &pre,vector<int> &post,int &idxPre,int sPo,int ePo,auto &mp){
        if(idxPre == pre.size() || sPo > ePo){
            return NULL;
        }

        int element = pre[idxPre++];

        TreeNode* root = new TreeNode(element);

        if(sPo == ePo){
            return root;
        }

        int pos = mp[pre[idxPre]]; 

        root->left = solve(pre,post,idxPre,sPo,pos,mp);
        root->right = solve(pre,post,idxPre,pos+1,ePo-1,mp);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int,int> mp;

        for(int i=0; i<post.size(); i++){
            mp[post[i]] = i;
        }

        int preIdx = 0;

        return solve(pre,post,preIdx,0,post.size()-1,mp);
    }
};