class Solution {
public:
    
    int findBestValue(vector<int>& arr, int target) 
    {
        if( arr.size() == 0)
            return 0;
        
        sort(arr.begin(),arr.end());
        
        int u = 0;
        for(int x: arr)
            u = max(u,x);
        
        int k = -1;
        
        for( int b = u; b >= 1; b/=2)
            while( k+b <= u && !simulate(arr,k+b,target))
                k += b;
        
        cout << k << endl;
        
        int i = upper_bound(arr.begin(),arr.end(),k) - arr.begin();
        int sum = 0;
        for( int j =0 ;j <i;j++)
            sum += arr[j];
        sum += (k)*(arr.size() - i);
        int diff1 = abs(sum-target);
        
        i = upper_bound(arr.begin(),arr.end(),k+1)- arr.begin();
        sum = 0;
        for( int j =0 ;j <i;j++)
            sum += arr[j];
        sum += (k+1)*(arr.size() - i);
        int diff2 = abs(sum-target);
                        
        if( diff2 < diff1 )
            return k+1;
        return k;
        
    }
    bool simulate(vector<int>& arr,int val,int target)
    {
        
        int i = upper_bound(arr.begin(),arr.end(),val) - arr.begin();
        int sum = 0;
        int t = target;
        for( int j =0 ;j <i;j++)
            sum += arr[j];
        sum += val*(arr.size() - i);
        
        
        if( sum >= target)
            return true;
         
        
        return false;
        
    }
};
