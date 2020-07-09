class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        if( stones.empty())
            return 0;
        
        int sum = accumulate(stones.begin(),stones.end(),0);
        int S = sum;
        sum /= 2;
        int n = stones.size();
        vector<vector<int> > dp(n +1 ,vector<int>(sum+1,0));
        
        for( int i = 1; i <= n; i++)
        {
            for( int j = 0; j <= sum; j++)
            {
                if( j >= stones[i-1])
                    dp[i][j] = max( dp[i-1][j], dp[i-1][j-stones[i-1]] + stones[i-1]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        int S2 = dp[n][sum];
        
        return S-2*S2;
        
        
    }
    int DFSlastStoneWeightII(vector<int>& A) 
    {
      unordered_set<int> s1 = { 0 };
      for (auto i : A) 
      {
        unordered_set<int> s2;
        for (auto j : s1) 
            s2.insert({ j - i, j + i });
        swap(s1, s2);
      }
      return abs(*min_element(begin(s1), end(s1), [](int i, int j) { return abs(i) < abs(j); }));
    }

};
