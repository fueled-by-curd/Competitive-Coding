class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int ans=0;
        int sz=0;;
        map<char,int> pos;
        int l=0,r=0;
        char c = ' ';
        while(r<s.size() && l <s.size())
        {
            c = s[r];
            if(pos.find(c) != pos.end())
            {
                if(pos[c]<l)
                    sz++;
                else 
                {
                    l=pos[c]+1;
                    sz=r-l+1;
                }
            }
            else
                sz++;
            pos[c]=r;
            ans=max(ans,sz);
            r++;
            
        }
        return ans;
    
        
        
    }
};