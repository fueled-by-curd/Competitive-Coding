#include<bits/stdc++.h>
using namespace std;
int customBsearch1(vector<int>& a,int x)
{
	int k =-1;
	for( int b = a.size()/2;b >= 1; b = b/2 )
		while( b+k < a.size() && (a[b+k] < x))
			k +=b;

	return k+1;
}

int customBsearch2(vector<int>& a,int x)
{
	int k =-1;
	for( int b = a.size()/2;b >= 1; b = b/2 )
		while( b+k < a.size() && (a[b+k] <= x))
			k +=b;
		
	return k+1;
}


int main()
{
	vector<int> a = {1,2,4,5,7,9,10};
	//cout <<
	auto it1 = lower_bound(a.begin(),a.end(),5);
	auto it2 = upper_bound(a.begin(),a.end(),5);

	cout << it1 - a.begin() << " " << *it1 << endl;
	cout << it2 - a.begin() << " " << *it2 << endl;


	int i = customBsearch1(a,5);
	int j = customBsearch2(a,5);

	cout << i << " " << a[i] << endl;
	cout << j << " " << a[j] << endl;




}


