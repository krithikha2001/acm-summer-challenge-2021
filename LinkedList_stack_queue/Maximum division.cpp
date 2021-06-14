
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
   // map<string,int> mp;
    string prev;
    string s;
     int cnt=0;
    for(int i=0;i<str.size();i++)
	{
		if(i==0)
		{
		prev=str[i];cnt++;continue;
		}
		
   		 if(str.substr(i,1)==prev && prev.size()==1 && i==str.size()-1)
    	{
    		prev=str[i]+prev;
		}
    	else if(str.substr(i,1)==prev && prev.size()==1)
    	{
    	//	prev=str[i]+str[i++];
    		prev=str.substr(i,2);
    		i++;
    		cnt++;
		}
		else if(prev.size()==2)
    	{
    		prev=str[i];
    		cnt++;
		}
		else if(str.substr(i,1)!=prev && prev.size()==1)
		{
			prev=str[i];
			cnt++;
		}
    } 
    cout<<cnt;
          return 0;
}


