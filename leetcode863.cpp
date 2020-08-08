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
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        tra(root);
        unordered_set<TreeNode*>us;
        queue<TreeNode*>q{{target}};
        while(K--){
            int len=q.size();
            for(int i=0;i<len;++i){
                TreeNode*cur=q.front();q.pop();
                us.insert(cur);
                if(cur->left&&!us.count(cur->left))q.push(cur->left);
                if(cur->right&&!us.count(cur->right))q.push(cur->right);
                if(um[cur]&&!us.count(um[cur]))q.push(um[cur]);
            }
        }
        vector<int>ret;
        while(!q.empty()){
            ret.push_back(q.front()->val);
            q.pop();
        }
        return ret;
    }
    void tra(TreeNode*root){
        if(root->left){
            um[root->left]=root;
            tra(root->left);
        }
        if(root->right){
            um[root->right]=root;
            tra(root->right);
        }
    }
private:
    unordered_map<TreeNode*,TreeNode*>um;
};
