class Solution {
public:
    int pivot(vector<int>& nums)
    {
        int l = 0;
        int r = nums.size()-1;
        int mid = (r+l)/2;
        
        while(l<r)
        {
            mid = (r+l)/2;
            
            if(nums[l] <= nums[mid] && nums[mid+1] <= nums[r])
                return mid;
            else if(nums[mid+1] > nums[r])
                l = mid+1;
            else if(nums[l] > nums[mid] )
                r = mid;
        }
        return mid;

    }
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        if( n == 0)
            return -1;
        int k= pivot(nums);
        
        
        
        //cout << k+1 << endl;
        vector<int>::iterator i   = nums.begin() + k +1;
        
        if( binary_search(nums.begin(),i,target))
        {
            //cout<<"Found 1";
            return lower_bound(nums.begin(), i,target) - nums.begin();
        }
        else if( binary_search(i,nums.end(),target))
        {
            //cout<<"Found 2";
            return lower_bound(i,nums.end(),target) - nums.begin();
        }
        else 
            return -1;

        //return 0;
        
    }
};
