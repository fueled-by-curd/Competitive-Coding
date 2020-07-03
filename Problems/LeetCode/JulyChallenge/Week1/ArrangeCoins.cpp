class Solution {
public:
    int arrangeCoins(int n) 
    {
        if( n <=0)
            return 0;
        double x = -0.5 + sqrt( 2* (long)n + 0.25);
        return (int)x;
    }
};
