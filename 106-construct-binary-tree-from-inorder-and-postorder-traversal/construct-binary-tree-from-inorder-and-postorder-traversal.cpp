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
    TreeNode* build(vector<int> &in,vector<int> &post,int &index,int sIn,int eIn,auto &mp){
        if(index < 0 || sIn > eIn){
           return NULL;
        }

        int element = post[index--];

        TreeNode* root = new TreeNode(element);

        int pos = mp[element];

        root->right = build(in,post,index,pos+1,eIn,mp);

        root->left = build(in,post,index,sIn,pos-1,mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        unordered_map<int,int> mp;

        for(int i=0; i<in.size(); i++){
            mp[in[i]] = i;
        }

        int index = post.size()-1;

        return build(in,post,index,0,in.size()-1,mp);
    }
};