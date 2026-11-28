/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void makeGraph(TreeNode* root,auto &graph){
        if(root == NULL){
            return;
        }

        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        makeGraph(root->left,graph);
        makeGraph(root->right,graph);
    }

    void dfs(int node,int parent,int k,vector<int> &ans,auto &graph){
        if(k == 0){
            ans.push_back(node);
            return;
        }

        for(int x : graph[node]){
            if(x != parent){
                dfs(x,node,k-1,ans,graph);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> graph[501];

        makeGraph(root,graph);

        vector<int> ans;

        int node = target->val;

        dfs(node,-1,k,ans,graph);

        return ans;
    }
};