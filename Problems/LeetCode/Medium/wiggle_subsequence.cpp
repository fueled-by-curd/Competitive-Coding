class Solution {
public:
int wiggleMaxLength(vector<int>& nums) 
{
        if(nums.size() == 0)
            return 0;
        int prev=0;
        int current=0;
        
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            int diff = nums[i] - nums[i-1];
            if(diff != 0)
            {
                current = (diff > 0) ? 1 : -1;
                if(current!=prev)
                {
                    prev = current;
                    count++;
                }
            }
        }
    return count;
}
};
