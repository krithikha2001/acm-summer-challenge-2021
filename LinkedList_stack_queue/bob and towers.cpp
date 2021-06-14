

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n;
	cin >> n;										// Reading input from STDIN
	ll a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	ll ans = 0;
	int f=0;
	ll sum=0,min=LLONG_MAX;
	for(int start_index = 0;start_index < n; ++start_index)					//O(n)		
	{
		sum = 0;
		min=LLONG_MAX;
		f=0;
		for(int sub_array_size = start_index;sub_array_size < n; ++sub_array_size)	//O(n)	
		{
			if(min>a[sub_array_size])
		{
			if(sum!=0)
			sum/=min;
			min=a[sub_array_size];
			f=1;
		}

			if(f==1)
			{
				sum*=min;
			}
			sum+= a[sub_array_size]*min;	//Last element of the new Subarray
			f=0;
			ans = max(ans,sum);
			//cout<<sum<<ans<<f<<min<<start_index<<sub_array_size<<"\n";
		}
	}

	cout<<ans;
}

// Write your code here

