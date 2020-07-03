class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) 
    {
        vector<int> prevDay = cells;
        if( N <= 0)
            return cells;
        int n = cells.size();
        
        vector<int> cP = cells;
        
        for( int i = 1; i < n-1 ; i++)
                cP[i] = (prevDay[i-1] == prevDay[i+1]); 
        cP[0] = 0;
        cP[n - 1] = 0;
        
        cells = cP;
        N--;
        int day = 0;
        
        while( N-- > 0)
        {
            prevDay = cells;
                
            for( int i = 1; i < n-1 ; i++)
                cells[i] = (prevDay[i-1] == prevDay[i+1]); 
            day++;
            if( cP == cells)
                N %= day;
            
            
        }
        
        return cells;
        
    }
};
