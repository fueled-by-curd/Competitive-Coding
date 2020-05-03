class Solution {
public:

    map<int,string> dig2alpha;
    vector<string> ans;

    
    void compute(string digits, string res, int pos) 
    {

        if(pos>=digits.size()) 
            return;
        string currStr = dig2alpha[digits[pos]-'0']; 
    
        for(int i=0; i<currStr.size(); i++) 
        {

            compute(digits, res+currStr[i], pos+1);//recursive call

            if(pos==digits.size()-1) 
                ans.push_back(res+currStr[i]);
        
        }
    } 

    vector<string> letterCombinations(string digits) 
    {
        dig2alpha[2] = "abc";
        dig2alpha[3] = "def";
        dig2alpha[4] = "ghi";
        dig2alpha[5] = "jkl";
        dig2alpha[6] = "mno";
        dig2alpha[7] = "pqrs";
        dig2alpha[8] = "tuv";
        dig2alpha[9] = "wxyz";



        compute(digits, "", 0);
        return ans;
    }
};
