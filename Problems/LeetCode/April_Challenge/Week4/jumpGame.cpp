class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int lastIndex = 0;
        for(int i = 0; i <nums.size()-1;i++)
        {
            lastIndex = max(lastIndex,i+nums[i]);
            if(lastIndex == 0 || lastIndex <i+1)
                return false;
        }
        
            
        cout << lastIndex;
        if( lastIndex>= nums.size()-1)
            return true;
        return false;
    }

};
