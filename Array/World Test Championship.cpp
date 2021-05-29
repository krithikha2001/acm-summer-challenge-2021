#include <bits/stdc++.h>
//#include <math.h>
#define ll long long
using namespace std;


int main() {
	ll t;
	cin >> t;
	ll n,nd;
	while(t--)
	{
		cin>>n;
		nd=n/2;
		if(2*nd==n)
		nd--;
		cout<<nd<<"\n";
	}								
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n,m;
	cin >> n>>m;
	if(n==m)
	{cout<<-1;return 0;}
	vector<ll> a(n);
	for(ll i=0;i<n;i++)
		{
		cin>>a[i];
		}

    vector<pair<ll, ll> > vp;

    for (ll i = 0; i < n; ++i) {
        vp.push_back(make_pair(a[i], i));
    }

    sort(vp.begin(), vp.end());
  while(m>0)
  {
  a[vp[m-1].second]=-1;
  	m--;
  }
}

	for(ll i=0;i<a.size();i++)
	{
		
		if(a[i]!=-1)
		cout<<a[i]<<" ";
	}								// Reading input from STDIN
}
