class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int count = 0;
        int l=0,r=0;
        int n = nums.size();
        int sum = 0;
    
        /*
        while(l<n )
        {
            sum = 0;
            r = l;
            while(r<n )
            {
                sum += nums[r];
                if(sum == k)
                {
                    count++;
                }
                r++;
            }
            l++;
            
        }
                
        return count;
        */
        return subarraySum_On(nums,k);
        
    }
    int subarraySum_On(vector<int>& nums, int k) 
    {
        map<int,int> cumSum;
        cumSum[0] = 1;
        int sum = 0;
        int count = 0;
         for(int i=0;i< nums.size();i++)
         {
             sum +=nums[i];
             if(cumSum.find(sum-k) != cumSum.end())
                 count+=cumSum[sum -k];
             if(cumSum.find(sum) != cumSum.end())
                cumSum[sum]++;
             else
                 cumSum[sum] = 1;
             
         }
        return count;
        
    }
    
    
};
