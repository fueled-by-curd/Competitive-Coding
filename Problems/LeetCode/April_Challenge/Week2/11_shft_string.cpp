class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) 
    {
        int shft = 0;
        string ans = "";
        for(int i=0;i<shift.size();i++)
            shft += (shift[i][0] == 0) ? -shift[i][1] : shift[i][1];
        
        
        if(shft == 0 || abs(shft)%s.size() == 0)
            return s;
        else if(shft < 0)
        {
            shft = (abs(shft))%s.size();
        
            ans = s.substr(shft);
            ans += s.substr(0,shft);
        }
        else
        {
            shft =s.size() -  (abs(shft))%s.size();
            //reverse(s.begin(),s.end());
            ans = s.substr(shft);
            ans += s.substr(0,shft);
            
            
        }
        return ans;
        
        
    }
};