#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	ll ds,t;
	cin >> n>>m>>ds>>t;			
	vector<ll> w(n);
	vector<ll> c(n);
	vector<ll> d(m);
	for(int i=0;i<n;i++)
	{
		cin>>w[i]>>c[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>d[i];
	}
	
	sort(d.begin(),d.end());
//	for(int i=0;i<m;i++)
//	{
//		cout<<d[i];
//	}
	ll sub=0,maxd=0;
	for(int i=1;i<m;i++)
	{
		sub=d[i]-d[i-1];
//		cout<<"sub<"<<sub;
		if(maxd<sub)
			maxd=sub;
	}
	sub=ds-d[m-1];
	if(maxd<sub)
			maxd=sub;
//	cout<<"maxd"<<maxd;
int ind=-1;
	ll tw=LLONG_MAX;

	if(ds>t)
	{
		cout<<"-1\n";
	}
	else if (ds==t)
	{
		maxd*=2;
		for(int i=0;i<n;i++)
		{
			if(c[i]>=maxd)
		{
			if(tw>w[i])
				{tw=w[i];
				//ind=i;
				}
		}
		}
		if(tw!=LLONG_MAX)
			{cout<<tw<<"\n";return 0;}							// Reading input from STDIN
	}
	
	else if((ds)<t)
	{	
while(ind!=0)
{
	tw=LLONG_MAX;
	ind=0;
	
	for(int i=0;i<n;i++)
	{
		if(c[i]>=maxd)
		{
			if(tw>w[i])
				{tw=w[i];ind=i;}
		}
	}
 
	if(tw==LLONG_MAX)
		tw=-1;
	if((ds+1)*2 <= t || tw==-1)
	{cout<<tw<<"\n";return 0;}							// Reading input from STDIN
	else
	{
		ll time=0;
		for(int i=1;i<m;i++)
	{
		//if(time>t)
		//{
		//	c[ind]=-1;w[ind]=-1;continue;
		//}
		sub=d[i]-d[i-1];
		if(sub<(tw/2))
			{
				time+=sub;
			}
		else
		{
			time+=2*(sub);
		}	
//		cout<<"sub<"<<sub;
	}
	sub=ds-d[m-1];
	if(sub<(tw/2))
	{
				time+=sub;
	}
		else
		{
			time+=2*(sub);
		}	
		if(time>t)
		{
			c[ind]=-1;w[ind]=-1;continue;
		}
		else
		{
			cout<<tw<<"\n";return 0;
		}
	}
}
	cout<<-1<<"\n";							// Reading input from STDIN
	}
	return 0;
}
