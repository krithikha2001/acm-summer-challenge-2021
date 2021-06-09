
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	int t;
	cin >> t;
	ll n;
	while(t--)
	{
		cin>>n;

		ll *a;
		a=(ll*)malloc(n*sizeof(ll));
		//int y=1;
		for(ll i=0;i<n;i++)
		{
		//	cout<<"ask";
			cin>>a[i];
		
		}
		sort(a,a+n);
		
		
		if(a[0]!=1 && a[1]!=1)
		{cout<<1<<"\n";continue;}

		ll max=0;
		for(ll i=0;i<n;i++)
		{
		//	cout<<"ask"<<max;
			if(a[i]>max+1)
			{
				break;
				//cout<<max+1<<"\n";
				//continue;
			}
			else
			max+=a[i];
		}
		cout<<max+1<<"\n";

	}						
}
