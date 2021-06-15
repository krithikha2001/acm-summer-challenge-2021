#define ll long long
using namespace std;

int main()
{
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		cin>>n;
		//string a[n];
		vector<ll> a(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		ll ans=0;
		for (int i = 0; i < 32; i++) {
        int count = 0;
        	for (int j = 0; j < n; j++)
            	if ((a[j] & (1 << i)))
                	count++;
 
        ans += (count * (count-1) / 2);
    	}
		cout<<ans<<"\n";
		}
}
