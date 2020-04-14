#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
#define PUB push_back
#define PUF push_front
#define POB pop_back
#define POF pop_front
#define S second
#define F first

#define TRACE
#ifdef TRACE
#define trace1(x) cout<<#x<<"="<<x<<endl
#define trace2(x,y) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define trace3(x,y,z) cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define trace4(w,x,y,z) cout<<#w<<"="<<w<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define tracev(a) rep(II,0,a.size()) cout<<#a<<"["<<II<<"]="<<a[II]<<" "; cout<<endl;
#define tracea(a,n) rep(II,0,n) cout<<#a<<"["<<II<<"]="<<a[II]<<" "; cout<<endl;
#define tracevv(a)\
    {\
    rep(II,0,a.size()){\
        rep(JJ,0,a[II].size())\
            cout<<#a<<"["<<II<<"]["<<JJ<<"]="<<a[II][JJ]<<" ";\
        cout<<endl;\
        }\
    }
#define tracem(a,r,c)\
    {\
    rep(II,0,r){\
        rep(JJ,0,c)\
            cout<<#a<<"["<<II<<"]["<<JJ<<"]="<<a[II][JJ]<<" ";\
        cout<<endl;\
        }\
    }
#else
#define trace1(x)   
#define trace2(x,y)   
#define trace3(x,y,z)   
#define trace4(w,x,y,z)  
#define tracev(a) 
#define tracea(a,n)  
#define tracevv(a)  
#define tracem(a,r,c)  
#endif

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef pair<int,int> pii;
vector<vector<string>> groupAnagrams(vector<string> strs) 
{
    int l = strs.size();
    vector< pair<string,string> > v(l);
    
    set<string> s;
    for( int i=0;i<l;i++)
    {
        v[i].S = strs[i];
        sort(strs[i].begin(),strs[i].end());
        v[i].F = strs[i];
        
        s.insert(strs[i]);
    }
    sort(v.begin(),v.end());

    vector< vector<string> > ans(s.size());
    int j=0;
    set<string>::iterator itr = s.begin();
    rep(i,0,s.size())
    {   

        while(j<l)
        {
            if(v[j].F.compare(*itr)==0)
                ans[i].PUB(v[j++].S);
            else
                break;
        }
        itr++;
    }
    tracevv(ans)
    
    
    return ans;

}
int main()
{
    ios::sync_with_stdio(0);
    
    int n = 0;
    cin >> n;

    vector<string> stList(n);

    rep(i,0,n)
        cin >> stList[i];

    vector < vector<string> > ans;
    ans = groupAnagrams(stList);
    return 0;
}

/*
*/
