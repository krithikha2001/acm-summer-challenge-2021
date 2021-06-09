
// Sample code to perform I/O:
#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v(26);
	vector<char> st;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		v[s[i]-'a']++;
	}
	int odd=0,temp;
	char o;
	for(int i=25;i>=0;i--)
	{
	//	cout<<v[i]<<"v";
		if(v[i]==0)
		continue;
		if(v[i]%2==0)
			{
			temp=v[i]/2;
		//	cout<<"temp"<<temp;
			while(temp--){	
		//	cout<<"t"<<temp;
	//	cout<<char(i+'a');
			st.push_back(char(i+'a'));
			}
			}
		else 
		{	int j;
			for(j=0;j<i;j++)
			{
				if(v[j]%2!=0)
				{
					v[j]++;
					v[i]--;
					temp=v[i]/2;
					while(temp--){	
						st.push_back(char(i+'a'));
					}
				//	st.push_back(char(i+'a'));
					break;
				}
			}
			if(j==i)
			{
				odd++;o=char(i+'a');
				temp=--v[o-'a'];
				temp/=2;
				while(temp--)
				{
					st.push_back(o);
				}
			}
		}
	}
		for(int i=st.size()-1;i>=0;i--)
	{
		cout<<st[i];
	}
	if(odd>0)
		cout<<o;

	for(int i=0;i<st.size();i++)
	{
		cout<<st[i];
	}

	

}
