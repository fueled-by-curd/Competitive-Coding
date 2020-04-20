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
    TreeNode* bFP(vector<int>& preorder,int s,int e) 
    {
        //cout<<"s:" <<s<<" e:"<<e << " ROOT:" << preorder[s]<< endl;
       
        if( s>=e )
            return NULL;
        TreeNode* root = newNode();
        root->val = preorder[s];
        
        if(s+1 == e )
        {
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        
        int r = -1;   
        
        if(lower_bound(preorder.begin()+s+1,preorder.begin()+e,preorder[s]) != preorder.begin()+e )
            r = lower_bound(preorder.begin()+s+1,preorder.begin()+e,preorder[s]) - preorder.begin();
        
        //if(r != -1)
        //cout<<" r:" << r << " num:" << preorder[r]<< endl;
        
        if (r == s+1)
        {
            root->right = bFP(preorder,r,e);
            root->left = NULL;
            return root;
        }
        else
        {
            
            if( r != -1)
            {
                root->left = bFP(preorder,s+1,r); 
                root->right = bFP(preorder,r,e);
            }
            else
            {
                root->left = bFP(preorder,s+1,e); 
                root->right = NULL; 
            }
            
        }
        
      return root;
        
            
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        TreeNode* ans = bFP(preorder,0,preorder.size());
        return ans;
    }
    TreeNode* newNode()
    {
        return (TreeNode*)malloc(sizeof(TreeNode));
    }
    
};
