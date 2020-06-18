class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) 
    {
        int u =0;
        for(int x: weights)
            u += x;
        u++;
        int k=-1;
        for(int b = u; b >=1; b/=2)
            while( b+k <= u && !simulate(weights,b+k,D))
                  k += b;
        
        
        return k+1;
        
    }
    bool simulate(vector<int>& weights, int W, int D)
    {
        int sum = 0;
        int count = 1;
        for(int i = 0 ; i < weights.size(); i++)
        {
            if( weights[i] > W)
                return false;
            if( sum +weights[i] > W)
            {
                //cout << "HEY" << endl;
                sum = 0;
                count++;
                //-;
            }
            sum += weights[i];
        }
        
        //cout << count << endl;
        if( count <= D)
            return true;
        return false;
    }
};
