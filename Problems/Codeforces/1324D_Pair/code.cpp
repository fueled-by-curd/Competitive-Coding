#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
#define PUB push_back
#define PUF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second

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

int main()
{
	ios::sync_with_stdio(0);
	int l;
	
	cin >> l;

	//trace2(l1,l2);
	vector<long long int> v1(l);
	vector<long long int> v2(l);
	
	int i=0;
	long long int inp = 0;
	while(i < l && cin >> inp)
		v1[i++] = inp;
	i=0;
	while(i < l && cin >> inp)
		v2[i++] = inp;

	vector<long long int> a;
	vector<long long int> b;

	rep(i,0,l)
	{
		if(v1[i] > v2[i] )
			a.PUB(v1[i]-v2[i]);
		else
			b.PUB(v1[i] - v2[i]);
	}


	long long int count=a.size();
	count = count*(count-1)/2;
	
	sort(a.rbegin(),a.rend());
	sort(b.begin(),b.end());

	int j=0;
	rep(i,0,b.size())
	{
		while(j<a.size() && a[j] > -b[i])
			j++;
		count+=j;
	}



	cout << count << endl;
	return 0;
}
