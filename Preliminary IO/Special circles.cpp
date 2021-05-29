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
}
