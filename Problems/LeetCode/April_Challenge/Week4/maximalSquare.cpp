class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if(matrix.size() == 0)
            return 0;
        
        
        return maximalSquare_betterDP(matrix);
        
        /*
        int ans = 0;
        vector <vector<int> > dp(matrix.size()+1);
        
        for(int i = 0;i<dp.size();i++)
            dp[i] = vector<int>(matrix[0].size()+1,0);
        
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(matrix[i-1][j-1] == '1')
                    dp[i][j] = 1+min(min(dp[i-1][j-1],dp[j]),dp[i][j-1]);
                else
                    dp[i][j] = 0;
                
                ans = max(ans,dp[i][j]);
            }
        }
        
        return ans*ans;
        */
        
        
    }
    int maximalSquare_betterDP(vector<vector<char>>& matrix) 
    {
        if(matrix.size() == 0)
            return 0;

        
        
        int ans = 0;
        int prev = 0;
        int tmp = 0;
        vector <int > dp(matrix[0].size()+1,0);
        
        for(int i=1;i<matrix.size()+1;i++)
        {
            for(int j=1;j<matrix[0].size()+1;j++)
            {
                tmp = dp[j];
                if(matrix[i-1][j-1] == '1')
                    dp[j] = 1+min(min(dp[j-1],dp[j]),prev);
                else
                    dp[j] = 0;
                prev = tmp;    
                ans = max(ans,dp[j]);
            
            }
            
        }
        
        return ans*ans;
        
        
        
    }
    
};