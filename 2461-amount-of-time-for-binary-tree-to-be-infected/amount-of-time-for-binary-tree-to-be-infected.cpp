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
    void dfs(TreeNode* root,auto &mp){
        if(root == NULL){
            return;
        }

        if(root->left){
            mp[root->left] = root;
            dfs(root->left,mp);
        }

        if(root->right){
            mp[root->right] = root;
            dfs(root->right,mp);
        }
    }

    void find(TreeNode* root,int start,auto &q){
        if(root == NULL){
          return;
        }

        if(root->val == start){
            q.push(root);
            return;
        }

        find(root->left,start,q);
        find(root->right,start,q);
    }

    int solve(auto &q,auto &mp){
        int time = 0;

        unordered_set<TreeNode*> visited;
        visited.insert(q.front());

        while(!q.empty()){
            int n = q.size();

            while(n--){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left && !visited.count(temp->left)){
                    q.push(temp->left);
                    visited.insert(temp->left);
                }

                if(temp->right && !visited.count(temp->right)){
                    q.push(temp->right);
                    visited.insert(temp->right);
                }

                if(mp[temp] && !visited.count(mp[temp])){
                    q.push(mp[temp]);
                    visited.insert(mp[temp]);
                }
            }
            
            if(!q.empty()){
                time++;
            }
        }

        return time;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> mp;

        mp[root] = NULL;

        dfs(root,mp);

        queue<TreeNode*> q;

        find(root,start,q);

        return solve(q,mp);
    }
};