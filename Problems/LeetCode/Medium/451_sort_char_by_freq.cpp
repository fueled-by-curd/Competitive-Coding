class Solution {
public:
    string frequencySort(string s) 
    {
        
        if(s.size() == 1)
            return 0;


        map<char,int> freq;
        for(char x:s)
            if(freq.find(x) != freq.end())
                freq[x]++;
            else
                freq[x] = 1;
        
        vector<pair<int,char> > freq_chars;
        
        map<char,int>::iterator itr;
        for (itr=freq.begin(); itr!=freq.end(); itr++) 
        {
            freq_chars.push_back(make_pair(itr->second,itr->first));
            //cout << itr->second << " " <<itr->first << endl;
        
        }
        
        sort(freq_chars.rbegin(),freq_chars.rend());
        
               
        string ans = "";
        string tmp = " ";
        
        for(int i = 0;i<freq_chars.size();i++)
        {
            tmp.replace(0,1,1,freq_chars[i].second); 
            ans +=string_rep(tmp,freq_chars[i].first);
            //cout << tmp << " " <<freq_chars[i].first << endl;
        }
        
        return ans;
        
        
        
    }
    string string_rep(string c,int n)//performs character repetition in O(lg n) time
    {
        if(n == 1)
            return c;
        else
        {
            if(n%2 == 0)
                return string_rep(c+c,n/2);
            else
                return c+string_rep(c+c,n/2);
            
        }
        
        return c;
    }
};
