
#include <iostream>

using namespace std;

int main() {
	int n,m,q;
	cin>>n>>m>>q;
//	cout<<q<<"q";
int *a[n];
	for(int i=1;i<=n;i++)
	         a[i] = (int *)malloc(m * sizeof(int));

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	int dpc[2*n];//y
	int dpr[2*n];
	int r=1,h=1,v=1,i=1,j=1;

	while(1)
	{
		if(i==n+1)
		{
			dpc[r]=j;
			dpr[r]=i;
			break;
		}
		else if(j==m+1)
		{
			dpc[r]=j;
			dpr[r]=i;
			break;
		}
		if(h==0 && a[i][j]==0)
		{i++;continue;}
		if(h==1 && a[i][j]==0)
		{j++;continue;}
		if(a[i][j]==1 && h==0)
		{
			dpc[r]=j;
			dpr[r]=i;
			r++;
			j++;
			h=1;
			continue;
	
		}
		if(a[i][j]==1  && h==1)
		{
			dpc[r]=j;
			dpr[r]=i;
			r++;
			i++;
			h=0;
			continue;
		
		}


	}

	long long q1;
	while(q--)
	{
		cin>>q1;
		q1%=(2*r);
		if(q1==0)
			cout<<0<<" "<<1<<"\n";
		else if(q1<=r)
			cout<<dpc[q1]<<" "<<dpr[q1]<<"\n";
		else 
				cout<<dpc[2*r-q1]<<" "<<dpr[2*r-q1]<<"\n";

	}
}

