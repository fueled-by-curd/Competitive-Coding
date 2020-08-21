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
 class SolutionI {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==0) return 0;
        
        int dp[nums.size()+1];
        dp[0] = 0;
        dp[1] = nums[0];
        
        for (int i=1; i<nums.size(); i++)
            dp[i+1] = max(dp[i], dp[i-1]+nums[i]);
        
        return dp[nums.size()];
    }
};
 class SolutionII {
public:
    int rob(vector<int>& nums) 
    {
        if( nums.size() == 0)
            return 0;
        if( nums.size() == 1)
            return nums[0];
        
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        
        dp[1] = nums[0];
        
        for( int i = 1; i < n-1; i++)
            dp[i+1] = max( dp[i], dp[i-1] + nums[i]);
        
        int ans = dp[n-1];
        
        dp[1] = 0;
        dp[2] = nums[1];
        
        for( int i = 1; i < n; i++)
            dp[i+1] = max( dp[i], dp[i-1] + nums[i]);
        
        ans  = max( ans, dp[n]);
        return ans;
        
        
    }
};
class SolutionIII {
public:
    unordered_map<TreeNode*,int> dp;// recusive solution with memoization
    int rob(TreeNode* root) 
    {
        if( root == NULL)
            return 0;
        
        if( dp.find(root) != dp.end() )
            return dp[root];
        
        
        int a1 = rob(root->right) + rob(root->left);
        int a2 = 0;
        
        if(root->left != NULL)
            a2 += rob(root->left->right) + rob(root->left->left);
        if(root->right != NULL )
            a2 += rob(root->right->right) + rob(root->right->left);
        dp[root] =  max( root->val  + a2, a1);
        return dp[root];
    }
};
