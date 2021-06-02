#include <bits/stdc++.h>
using namespace std;
int inv(vector<int>& nums) {
	  vector<int> sorted;
      int result=0;
        for (int i = nums.size() - 1; i  >= 0; --i) {
            auto it = sorted.insert(lower_bound(sorted.begin(), sorted.end(), nums[i]), nums[i]);
            result =result+( it - sorted.begin());
        }
        return result;
    }
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	int q;
	cin >>n>>q;

	vector<int> arr(n);
	for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}

	int base=inv(arr);

	int a,b,t1,t2,bs;
		while(q--)
	{
		bs=base;
		cin>>a>>b;
		
		if(a==b)
		{
			cout<<base<<"\n";
			continue;
		}
		for(int j=0;j<a-1;j++)
		{
			if(arr[a-1]<arr[j])
			{
					bs--;
			}
		}//				cout<<"dec"<<bs;

		for(int j=a-1;j<n;j++)
		{
			if(arr[a-1]>arr[j])
			{
					bs--;
			}
		}				//cout<<"dec"<<bs;

		for(int j=0;j<b-1;j++)
		{
			if(arr[b-1]<arr[j] && j!=a-1)
			{
					bs--;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=b-1;j<n;j++)
		{
			if(arr[b-1]>arr[j]  && j!=a-1)
			{
					bs--;
			}
		}		//		cout<<"dec"<<bs;
		t1=arr[a-1];
		t2=arr[b-1];
		arr[a-1]=arr[b-1];
		arr[b-1]=t1;
		for(int j=0;j<a-1;j++)
		{
			if(arr[a-1]<arr[j])
			{
					bs++;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=a-1;j<n;j++)
		{
			if(arr[a-1]>arr[j])
			{
					bs++;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=0;j<b-1;j++)
		{
			if(arr[b-1]<arr[j] && j!=a-1)
			{
					bs++;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=b-1;j<n;j++)
		{
			if(arr[b-1]>arr[j]  && j!=a-1)
			{
			       // vect.push_back( make_pair(i,j) );
					bs++;
			}
		}			//	cout<<"dec"<<bs;

			cout<<bs<<"\n";

		arr[a-1]=t1;
		arr[b-1]=t2;
	}
	return 0;
}
