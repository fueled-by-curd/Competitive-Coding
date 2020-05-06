class Soultion{
public:
    int subarraySum(vector<int>& nums, int k) 
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
