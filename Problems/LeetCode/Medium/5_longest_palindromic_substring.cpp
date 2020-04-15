class Solution {
public:
    int expandFromMid(string s,int l,int r)
    {
        if(s.size() == 1 )
            return 1;
        while(r<s.size() && l>=0 && s[l] == s[r]) 
        {
            r++;
            l--;
        }
        
        return r-l-1;
        
    }
    string longestPalindrome(string s) 
    {
        if(s.size() == 1)
            return s;
        int n = s.size();
        int sz = 0;
        int l1 =0,l2 =0;
        int st = 0;
        int end = 0;
        
        for(int i=0;i<n;i++)
        {
            l1 = expandFromMid(s,i,i);
            l2 = expandFromMid(s,i,i+1);
            sz = max(l1,l2);
            if(sz > end - st +1)
            {
                st = i - (sz-1)/2;
                end = i+(sz/2);
            }
 
        }
        
        return s.substr(st,end-st+1);
    }
    
    
};
