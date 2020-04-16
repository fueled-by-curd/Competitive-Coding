class Solution {
public:
    bool checkValidString(string s) 
    {
        stack <pair<char,int> > st;
        stack <int> pos;
        int star = 0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                st.push({s[i],i});
                
            }
            else if(s[i] == ')')
            {
                if(st.size() != 0 )
                    st.pop();
                else
                {
                    if(star == 0)
                        return false;
                    star--;
                    pos.pop();
                    
                }
            }
            else
            {
                star++;
                pos.push(i);
            }
        }
        
        if(st.size() == 0 )
            return true;
        else if(st.size() <= star)
        {
            while(st.size() > 0)
            {
                if(st.top().second < pos.top())
                {
                    st.pop();pos.pop();
                }
                else
                    return false;
            }
            return true;
        }
        
        return false;
        
    }
};
