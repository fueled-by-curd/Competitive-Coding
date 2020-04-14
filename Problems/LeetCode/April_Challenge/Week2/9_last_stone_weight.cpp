class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        multiset<int> st;
        for(int x: stones)
            st.insert(x);
        if(st.size() == 1)
            return stones[0];
        int a=0;
        int b=0;
        int ans = 0;
        multiset<int>::iterator itr = st.end();
        //itr--;
        while(st.size() >=2)
        {
            itr = st.end();
            itr--;
            a = *itr;
            st.erase(itr);
            
            itr = st.end();
            itr--;
            b = *itr;
            st.erase(itr);
            
            
            if( a<=b)
                st.insert(b-a);
            else 
                st.insert(a-b);
            ans = a<=b? b-a:a-b;
            
            
        }
        
        return ans;
        
    }
};