
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;			
	while(t--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int ev=0;int z=0;

			if(a%2==0)
			++ev;
			if(b%2==0)
			++ev;
			if(c%2==0)
			++ev;
			if(d%2==0)
			++ev;

			if(a==0)
			z++;
			if(b==0)
			z++;
			if(c==0)
			z++;
			if(z==1)
			{
				if(ev==3||ev==4)
				{cout<<"Bob\n";continue;}
				else
				{cout<<"Alice\n";continue;}
			}
		//	cout<<ev;
			if(ev!=2)
			{
				cout<<"Bob\n";
			}
			else
					cout<<"Alice\n";

	}							// Reading input from STDIN
}

