class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        if( citations.size() == 0 )
            return 0;
        if( citations.size() == 1 )
            return (citations[0] > 0)? 1:0;
        
        int n = citations.size() ;
        int r = n;
        int l = 0;
        int m = l + (r-l)/2; ;
        int ans = 0;
        while( l < r )
        {
            m = l + (r-l)/2;
                
            if(citations[m] > n-m)
                r = m;
            else if( citations[m] < n-m)
                l = m + 1;
            else
                return citations[m];
                
            
        }
        //m = l + (r-l)/2;
        
        return (n - l);
    }
};
