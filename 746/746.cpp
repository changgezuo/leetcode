class Solution {
public:
    vector<int> res;
    unordered_map<int,int> m;
    void right(TreeNode* root, int level ,int max_level){
      if(root==NULL)return;
        
      if(max_level < level){
          m[level]++;
          if(m[level]==1){
          res.push_back(root->val);
          max_level = level;
          }    
      }  
      right(root->right,level+1,max_level);
      right(root->left,level+1,max_level);  
        
    }
    vector<int> rightSideView(TreeNode* root) {
       int max_level =0;
       right(root,1,max_level);
      return res;  
    }
};