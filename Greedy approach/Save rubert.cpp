

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	int t;
	cin>>t;
	ll n,m,k,nd;
	while(t--)
	{
		cin>>n>>m>>k;
		nd=n;
		ll r=0;
		
		while(n>k && m!=1)
		{
			r++;
			n/=m;
			nd=n;
		//	cout<<r<<n;
		}
	//				cout<<"hb"<<r<<n<<"ns"<<nd;
//ll nm=1;
	r+=ceil(double(nd)/k);
	//cout<<"CEil"<<ceil(double(nd)/k)<<double(nd)/k;
	cout<<r<<"\n";
	}
}
