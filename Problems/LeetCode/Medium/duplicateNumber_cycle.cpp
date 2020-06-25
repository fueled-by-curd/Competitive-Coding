class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int ans = 0;
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while( slow != fast);
        
        slow = nums[0];
        while( slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
            
        }
        return slow;
    }
    int findDuplicateN2(vector<int>& nums) 
    {
        int ans = 0;
        for( int i = 0; i < nums.size(); i++)
        {
            ans = nums[i];
            for( int j = i+1; j < nums.size(); j++)
            {
                //cout << (ans^nums[j]) <<endl;
                if( (ans^nums[j]) == 0)
                    return ans;
            }
        }
        return ans;
        
    }
};
