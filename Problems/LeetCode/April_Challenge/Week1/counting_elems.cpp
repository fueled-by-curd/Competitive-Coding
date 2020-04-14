class Solution {
public:
    int countElements(vector<int>& arr) 
    {
        set<int> s;
        for( int x:arr)
            s.insert(x);
        int c=0;
        for(int x:arr)
            if(s.find(x+1)!=s.end())
                c++;
        return c;
        
    }
};
