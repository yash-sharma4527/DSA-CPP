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
    void dfs(TreeNode* root,int v,int l,auto &mp){
        if(root == NULL){
            return;
        }

        mp[v][l].insert(root->val);

        dfs(root->left,v-1,l+1,mp);
        dfs(root->right,v+1,l+1,mp);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        map<int,map<int,multiset<int>>> mp;

        dfs(root,0,0,mp);

        for(auto &m : mp){ 
            vector<int> v;
            for(auto &m2 : m.second){
                for(auto &x : m2.second){
                    v.push_back(x);
                }
            }
            ans.push_back(v);
        }

        return ans;
    }
};