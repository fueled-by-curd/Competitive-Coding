class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0] = 1;
        suffix[n-1] = 1;
        
        for(int i = 1;i<n;i++)
            prefix[i] = nums[i-1]*prefix[i-1];
        
        for(int i = n-2;i>=0;i--)
            suffix[i] = nums[i+1]*suffix[i+1];
        
        for(int i=0;i<n;i++)
            prefix[i] *= suffix[i]; 
        
        return productOptimised(nums); 
        return prefix;    
        
    }
    vector<int> productOptimised(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] =1;
        ans[n-1] =1;
        
        int tmp = 1;
        for(int i=1;i<n;i++)
        {
            tmp *= nums[i-1]; 
            ans[i] = tmp;
        }
        
        tmp = 1;

        for(int i=n-2;i>=-1;i--)
        {
            ans[i+1] *= tmp;
            tmp *= nums[i+1]; 
        }
            
       
        
        return ans;    
        
    }
    
};
