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
    vector<vector<int>> ans;
    int height( TreeNode* root)
    {
        if( root == NULL)
            return 0;
        
        int l = 0;
        int r = 0;
        if( root->left)
            l = 1+height(root->left);
        if( root->right)
            r = 1+height(root->right);
        
        return max( l, r);
        
    }
    int H;
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        //ans.clear();
        if( root == NULL)
            return ans;
        int h = height( root);
        cout << h << endl;
        
        H = h;
        ans = vector<vector<int>>(h+1);
        level(root,0);
        
        return ans;
    }
    void level( TreeNode*  root, int h)
    {
        if( root == NULL)
            return;
        
        ans[H-h].push_back(root->val);
        level(root->left,h+1);
        level(root->right,h+1);
              
    }
    
  
};
