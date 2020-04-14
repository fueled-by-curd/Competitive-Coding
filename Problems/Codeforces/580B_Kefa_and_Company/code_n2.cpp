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
#define tracep(a) for(auto x: a) cout << x.first <<" "<< x.second << "\n";
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
#define tracep(a)	
#endif

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef pair<int,int> pii;
bool cmp(pair<long long int,long long int> a,pair<long long int,long long int> b)
{
	if(a.second > b.second)
		return true;
	else if(a.second == b.second && a.first > b.first)
		return true;
	else
		return false;
}
bool ok(int n ,vector<pair<long long int,long long int> > v, long long int x,long long int d)
{
	long long int a = (v[n].first-x + d);
	if(a > 0)
		return true;
	else
		return false;
}

bool ok1(int n ,vector<pair<long long int,long long int> > v, long long int x,long long int d)
{
	long long int a = (v[n].first-x- d);
	if(a > 0)
		return true;
	else
		return false;
}
pair<int,int> indexSearch(vector<pair<long long int,long long int> > v, long long int x,long long int d)
{

	int n = v.size();

	int k=-1;
	for(int b = n/2; b >=1 ; b= b/2)
	{
		while(b+k < n && !ok(b+k,v,x,d))
			k+=b;
	}
	int l=-1;
	for(int b = n/2; b >=1 ; b= b/2)
	{
		while(b+l < n && !ok1(b+l,v,x,d))
			l+=b;
	}

	
	return {k+1,l+1};

}

int main()
{
	ios::sync_with_stdio(0);
	int n; long long int d;
	cin>>n >>d;
	vector<pair<long long int,long long int> > v(n);
	
	int i=0;long long int x=0;long long int y=0;
	//trace2(n,d);

	while(cin >> x && cin >> y)
	{
		v[i++] = {x,y};
	}

	//tracep(v);
	sort(v.begin(),v.end());
	//tracep(v);
	//
	long long int sum = 0 ;
	long long int frf = 0 ;
	long long int mx = 0;
	long long int mn = 0;


	/*
	rep(i,0,n)
	{

		sum = v[i].second;
		mx = v[i].first;
		mn = v[i].first;
		rep(j,0,n)
		{
			if(j!= i && abs(mx - v[j].first) < d && abs(v[j].first - mn) <d ) 
			{
				sum += v[j].second;

				if(v[j].first >mx)
					mx = v[j].first;

				if(v[j].first <mn)
					mn = v[j].first;

			}
			//trace1(sum);
		}
		frf = max(frf,sum);
	}
	*/
	pair <int,int> indices;
	long long int sum1 = 0 ;
	long long int sum2 = 0 ;
	if(n==1)
		{
			cout << v[0].second <<endl;
			return 0;
		}

	rep(i,0,n)
	{
		sum =0;
		indices = indexSearch(v,v[i].first,d);

		mx = v[indices.first].first;
		mn = v[indices.second-1].first;
		

		sum1=0;sum2=0;
		rep(j,indices.first,indices.second)
		{

			if(abs(mx - v[j].first) < d  ) 
			{
				sum1 += v[j].second;
			}
			if(abs(v[j].first - mn) <d ) 
			{
				sum2 += v[j].second;
			}
			sum = max(sum1,sum2);

		}
		//cout << indices.first <<  " " << indices.second << " " << sum <<"\n";
		frf = max(frf,sum);

	}


	cout << frf << "\n";


}
