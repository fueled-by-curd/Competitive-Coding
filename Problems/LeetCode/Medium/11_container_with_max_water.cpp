class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int ans = 0;
        int l = 0;int r = height.size()-1;
        
        int a = 0,b=0;
        while(l<=r)
        {
            a = min(height[l],height[r]);
            b = r-l;
            ans = max(ans,a*b);
            if(height[l] < height[r])
                l++;
            else
                r--;

        }
        return ans;
        
        
    }
};
