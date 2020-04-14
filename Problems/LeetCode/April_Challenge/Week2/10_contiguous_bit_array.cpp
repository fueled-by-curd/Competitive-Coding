class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int count = 0 ;
        int ans = 0 ;
        map<int,int> cI ;
        for( int i=0;i<nums.size();i++)
        {
            
            count += nums[i] == 0? -1:+1;
            if(count == 0)
                ans = max(ans,i+1);
            else if(cI.find(count) != cI.end())
                ans = max(ans, i-cI[count]);
            else
                cI[count] = i;
        }
        
     return ans;   
    }
};