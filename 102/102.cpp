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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        if(!root)return ret;
        queue<TreeNode*>q{{root}};
        while(!q.empty()) {
            int len = q.size();
            vector<int>t;
            for(int i = 0; i < len; ++i) {
                TreeNode*cur = q.front();q.pop();
                t.push_back(cur -> val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            ret.push_back(t);
        }
        return ret;
    }
};