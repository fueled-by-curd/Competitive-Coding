class Solution {
public:
    string convert(string s, int numRows) 
    {
        if( numRows == 1 || numRows >= s.size() )
            return s;
        
        string ans = "";
        int n = 2*(numRows-1);
        int j= numRows;

        int i=0;
        int jmp = 0;
        while(j >0)
        {
            ans += s[numRows-j];
            i = numRows - j;
            jmp = 2*(j-1);
            while(i+n < s.size() )
            {
                if( j == numRows || j== 1 )
                    ans += s[i+n];
            
                else
                {
                   
                    ans += s[i + jmp];
                    ans += s[i + n ];
                        
                }
                
                i+= n;

            }
            if(i+jmp < s.size() && j>1 && j<numRows)
                ans += s[i+jmp];
            
            j--;
        
        }
        return ans;
        
            
        
    }
    
};

/*
LeetCode Solution
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};
*/
