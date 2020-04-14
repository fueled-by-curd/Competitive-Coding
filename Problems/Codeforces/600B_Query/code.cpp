#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
#define PUB push_back
#define PUF push_front
#define POB pop_back
#define POF pop_front

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

int bSearch(vector<long long int> v, long long int x)
{
	int k=0;
	for( int b=v.size();b>=1;b=b/2)
	{
		while(b+k <v.size() && v[b+k] <=x)
			k+=b;
	}
	
	if(v[k] <= x )
		return k+1;
	else
		return k;
}

int main()
{
	ios::sync_with_stdio(0);
	//return 0;

	int l1,l2;
	
	cin >> l1 >> l2;

	//trace2(l1,l2);
	vector<long long int> v1(l1);
	vector<long long int> v2(l2);
	
	int i=0;
	long long int inp = 0;
	while(i < l1 && cin >> inp)
		v1[i++] = inp;
	i=0;
	while(i < l2 && cin >> inp)
		v2[i++] = inp;

	tracev(v1);
	tracev(v2);
	sort(v1.begin(),v1.end());

	rep(i,0,l2)
	{
		printf("%d ",upper_bound(v1.begin(),v1.end(),v2[i])-v1.begin());
	}
	

}