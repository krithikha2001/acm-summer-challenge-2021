#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	long long n;
	cin >> n;										// Reading input from STDIN
	int r=0;
	while(n!=1)
	{
		if(n&1==1)
			n=-(~n);
		else
			n=n>>1;
		cout<<n<<"\t";
		r++;
	}
	cout<<r;
}
