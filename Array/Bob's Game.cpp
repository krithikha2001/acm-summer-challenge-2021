#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() { 
	ll n,p;
	cin >> n>>p;
	vector<ll> a(n);
	ll min=LLONG_MAX,ind=-1;
	for(ll i=0;i<n;i++)
	{	
		cin>>a[i];
		if(min>a[i])
		{min=a[i];ind=i;}
	}	
	if(p<ind+1){				
	a[ind]=(min*n)+(n-ind-1)+(p);							
	for(ll i=ind+1;i<n;i++)
	{
		a[i]-=(min+1);
	}
	for(ll i=0;i<p;i++)
	{
		a[i]-=(min+1);
	}
	for(ll i=p;i<ind;i++)
	{
		a[i]-=(min);
	}
	for(ll i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	} 

	}
	else if(p==ind+1)
	{
		for(ll i=0;i<n;i++)
		{
			a[i]-=(min);
		}
		a[ind]=(min*n);		
		for(ll i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
	}
	else
	{
		a[ind]=(min*n)+(p-ind-1);
		//a[ind]+=(min*n);				
		for(ll i=ind+1;i<p;i++)
		{
			a[i]-=(min+1);
		}
		for(ll i=0;i<ind;i++)
		{
			a[i]-=(min);
		}
		for(ll i=p;i<n;i++)
		{
			a[i]-=(min);
		}
		for(ll i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
	}
	return 0;
}
