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
    int ht(TreeNode* root)
    {
        if( root == NULL)
            return 0;
        else
        {
            return 1+max(ht(root->left),ht(root->right));
        }
        
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        int ans=0;
        
        int h1 = ht(root->left);
        int h2 = ht(root->right);
        
        int d1 = diameterOfBinaryTree(root->right);
        int d2 = diameterOfBinaryTree(root->left);
        
        return max(h1+h2, max(d1,d2) );
        
    }
	int diaOn(TreeNode* root, int* ht) 
    {
        if(root == NULL)
            return 0;
        
        int ans=0;
        
        int h1 = 0;
        int h2 = 0;
        if(root == NULL)
            *ht = 0;
        
        
        int d1 = diaOn(root->right,&h1);
        int d2 = diaOn(root->left,&h2);
        
        *ht = max( h1 , h2)+1;        
        
        return max( h1+h2, max(d1,d2) );
        
    }
    
};