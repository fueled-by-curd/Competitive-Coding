class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        int sum = 0;
        for( int x: nums)
            sum += x;
        
        if( sum > 1000 || sum < S || (sum - S)%2 != 0 )
            return 0;
        
        // if the excess in sum to get S is not even, we cannot divide
        // - and + among elems to get S + 0 (nullifying the excess with equal halves of +exess/2 and -excess/2 ) 
        
        
        int target = (sum - S)/2;
        vector<int> dp ( target + 1 , 0);
        
        dp[0] = 1; // indicating a succesfull combination of - and + to get S. used to carry it over to other portions
        // 0/1 Knapsack solution optimised from 2D to 1D 
        for( int i = 0 ; i < nums.size() ; i++ )
        {
            for( int j = target; j >= nums[i]; j--)
                dp[j] += dp[j - nums[i]];
            
        }
        
        return dp[target];
        
    }
    int findWays(vector<int>& nums, int S, int i) 
    {
        //TLE Solution
        if ( i == nums.size()  && S == 0)
            return 1;
        if( i >= nums.size() )
            return 0;
        int ans = 0;
        
        ans += findWays(nums, S - nums[i ] , i+1) + findWays(nums, S + nums[i], i + 1);
        
        //sum[S] = ans;
        return ans;
        
    }
    int findTargetSumWays2D_DP(vector<int>& nums, int S) 
    {
        //return findWays(nums,S,0);
        if( S > 1000)
            return 0;
        
        int n = nums.size();
        vector<vector<int> > dp( n , vector<int> ( 2001,0));
        dp[0][nums[0]  + 1000] = 1;
        dp[0][-nums[0] + 1000] += 1;
        
        for (int i = 1; i < n; i++) 
        {
            for (int sum = -1000; sum <= 1000; sum++) 
            {
                if (dp[i - 1][sum + 1000] > 0) 
                {
                    dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
                    dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
                }
            }
        }
        
        
        
        return dp[n-1][S + 1000];
        
        
    }
};
