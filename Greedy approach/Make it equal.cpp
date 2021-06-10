

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	//while(1)
	//{
	
	int n1;
	cin >> n1;

	vector<ll> a(n1);
	ll suma=0,sumb=0;
	for(int i=0;i<n1;i++)
	{
		cin>>a[i];
		suma+=a[i];
	}
		int n2;
	cin>>n2;
		vector<ll> b(n2);

	for(int i=0;i<n2;i++)
	{
		cin>>b[i];
		sumb+=b[i];
	}
	if(suma!=sumb)
	{
		cout<<"-1\n";return 0;
	}
	int i=0,j=0,f=0,r=0;
	suma=0,sumb=0;
	while(i<n1 && j<n2)
	{
//	cout<<"idjd"<<i<<j<<suma<<sumb<<f<<"\tR"<<r;
	
		if((a[i]==b[j]) && (suma==sumb))
		{
			i++;j++;
			r++;
			suma=0;
			sumb=0;
	//		f=0;
			continue;
		}
		else if((a[i]!=b[j]) && (suma==sumb) )
		{
			suma+=a[i];
			sumb+=b[j];
			continue;
		}
	
		while(suma!=sumb && i<n1 && j<n2)
		{
			//	cout<<"\n\twhile"<<i<<j<<suma<<sumb<<f<<"\tR"<<r;
			if(suma<sumb)
			{
				i++;
				suma+=a[i];
			}
			else if(sumb<suma)
			{
				j++;
				sumb+=b[j];
			}
		}
		if(suma==sumb && f==0)
		{
		//f=1;
		r++;
		suma=0;sumb=0;
		}
		i++;j++;
	}
	cout<<r<<"\n";
//	cout<<"1\n";	
	
	
//}
}
