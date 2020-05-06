class Solution {
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        /*
        int  ans = m;
        for( int x = m; x<=n; x++)
        {
            
            if(ans == 0)
                return ans;
            if(x == 2147483647)
                return ans;
            ans = ans & x;
        }
        return ans;
        */
        int c=0;
        while(m!=n)
        {
		    m>>=1;
		    n>>=1;
		    ++c;
	    }
	    
        return n<<c;
        
        
    }
    
};
