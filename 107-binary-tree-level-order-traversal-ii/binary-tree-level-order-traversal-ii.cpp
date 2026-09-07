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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        queue<TreeNode*> q;
        stack<TreeNode*> s;

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL){
                s.push(NULL);

                if(!q.empty()){
                    q.push(NULL);
                }
            }

            else{
                s.push(temp);

                if(temp->right) q.push(temp->right);

                if(temp->left) q.push(temp->left);
            }
        }

        vector<int> level;

        s.pop();

        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();

            if(temp == NULL){
                ans.push_back(level);
                level.clear();
            }

            else{
                level.push_back(temp->val);
            }
        }

        ans.push_back({root->val});

        return ans;
    }
};