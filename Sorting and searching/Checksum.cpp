
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	int n;
	while(t--)
	{
		cin>>n;
		vector<long long> a(n);
		for(int i=0;i<n;i++)
		cin>>a[i];
		sort(a.begin(),a.end());
		long long check=0;
		int j=n;
			for(int i=n-1;i>=(n/2);i--)	
	{
						check+=a[i]*j;
					//	cout<<check<<"*"<<j<<"\t";
						j-=2;
	}		
	j=n-1;
	if (n%2==0)
	{
			for(int i=0;i<=(n/2);i++)	
	{
		if(j<=0)
		break;
						check-=a[i]*j;
					//	cout<<check<<"*"<<j<<"\t";
						j-=2;
	}		
	}
	else
	{
				for(int i=0;i<(n/2);i++)	
	{
			if(j<=0)
		break;
						check-=a[i]*j;
					//	cout<<check<<"*"<<j<<"\t";
						j-=2;
	}		
	}

		cout<<check<<"\n";

	}										// Reading input from STDIN
}

