class Solution {
public:
    bool backspaceCompare(string S, string T) 
    {
        string s1 = pre_process(S);
        string s2 = pre_process(T);
        
        if(s1.compare(s2) == 0)
            return true;
        return false;
        
        
    }
    string pre_process(string s)
    {
        string s1 = "";
         int l1=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != '#' )
                s1 += s[i];
            else
            {   
                l1 = s1.size();
                if( l1>0 )
                    s1 = s1.substr(0,l1-1);
                
            }
        }
        return s1;
    }
};