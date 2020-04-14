class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int,int> m;
        for( int i=0;i<nums.size();i++)
            m[nums[i]] = i;
        
        for(int i=0;i<nums.size();i++)
            if(m.find(target-nums[i])!=m.end())
                if(m[(target-nums[i])]!=i)
                    return {i,m[target-nums[i]]};
        
        
        
        return {0,0};
        
        
        
    }
};