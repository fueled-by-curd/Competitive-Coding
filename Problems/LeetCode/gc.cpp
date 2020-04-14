#define F first
#define S second
//#include <vector.h>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int l = strs.size();
        vector< pair<string,string> > v(l);
        set<string> s;
        for( int i=0;i<l;i++)
        {
            v[i].S = strs[i];
            sort(strs[i].begin(),strs[i].end());
            v[i].F = strs[i];
            
            s.insert(v[i].F);
        }
        
        sort(v.begin(),v.end());
        sort(s.begin(),s.end());
        
        vector<vector<string> > ans(s.size());
        vector<string> tmp;
        int j=0;int i=0;
        for(auto x:s)
        {
            for(;j<l;j++)
                if(v[j].F.compare(x)==0)
                    ans[i++].push_back(v[j].S);
                else
                    break;
        }
        return ans;
            
        
        
    }
};
int main

