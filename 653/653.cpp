#include<unordered_map>

using namespace std;

struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        tra(root);
        return findTar(root, k);
    }

    void tra(TreeNode * root){
        if(!root)return;
        um[root->val]++;
        tra(root->left);
        tra(root->right);
    }

    bool findTar(TreeNode* root, int k){
        if(!root)return false;
        int cnt = um[k - root->val];
        if(k == root->val * 2){
            if(cnt >= 2)return true;
        }else{
            if(cnt >= 1)return true;
        }
        return findTar(root->left, k) || findTar(root->right, k);
    }
private:
    unordered_map<int, int>um;
};