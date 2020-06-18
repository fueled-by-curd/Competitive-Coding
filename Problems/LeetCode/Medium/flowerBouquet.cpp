class Solution {
public:
    int M;
    int K;
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        if( m*k > bloomDay.size() || k == 0)
            return -1;
        if( m == 0)
            return 0;
        int ans = 0;
        K = k;
        M = m;
         
        int upperLimit = 0;
        for( int x : bloomDay)
           upperLimit = max(x,upperLimit);
        
        int lowerLimit = upperLimit;
        for(int x:bloomDay)
            lowerLimit = min(x,lowerLimit);
        cout << upperLimit << endl;
        /*
        */
        int key = -1;
        for( int b =1+ upperLimit; b >=1; b /=2)
            while(b+k <= upperLimit && !simulate(bloomDay,b+key))
                key += b;
        return key+1;
        
        
        /*
        while( lowerLimit < upperLimit)
        {
            int m = lowerLimit + (upperLimit - lowerLimit)/2;
            if( simulate(bloomDay,m) )
                upperLimit = m;
            else
                lowerLimit = m+1;
        }
        return lowerLimit;
        */
        
        
    }
    bool simulate(vector<int>& bloomDay, int m)
    {
        int n = bloomDay.size();
        int mid = m;
        int bouquet = 0;
        int adjacent = 0;
        for( int i = 0 ; i < n; i++)
        {
            if( bloomDay[i] <=  mid)
            {
                adjacent++;
                if( adjacent == K)
                {
                    bouquet++;
                    adjacent = 0;
                }
            }
            else
                adjacent = 0;
        }
        
        if( bouquet >= M)
            return true;
        
        return false;
    }
    
};
