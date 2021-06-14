#include <bits/stdc++.h>
using namespace std;
class Node
{
	public:
	Node* next;
	Node* prev;
	int v;
};
/*void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<node->v<<" ";
        node = node->next;
    }
}*/
int main()
{
	int n;
	cin>>n;
	int pr=0,res=0;
	int data=0;
	Node* head=new Node();
	cin>>data;
	head->v=data;
			head->next=NULL;
			head->prev=NULL;
	Node* nn=head;
	pr=data;
	for(int i=1;i<n;i++)
	{
		cin>>data;
		if(pr<data)
		{
			Node* temp=new Node();
			temp->v=data;
			temp->next=NULL;
			temp->prev=NULL;
			//cout<<nn->v;
			nn->next=temp;
			temp->prev=nn;
			nn=nn->next;
		}
		else
		{
			if(res==0)
			res=1;
		}
		pr=data;
	}
	//nn=nn->prev;
	//cout<<"P"<<nn->v;
	//printList(head);
	int f=0;
	Node* curr=nn;
	while(f==0)
	{
		while(nn->next!=NULL)
		{
			nn=nn->next;
		//	cout<<nn->v;
		}
		while(nn->prev!=NULL)
		{
			if(nn->v < nn->prev->v)
			{
				//		cout<<nn->v;

				//cout<<"oe";
				if(nn->next!=NULL && nn->prev!=NULL)
				nn->prev->next=nn->next;
				else if(nn->next==NULL)
					nn->prev->next=NULL;
				
				if(nn->prev==NULL && nn->next!=NULL)
				nn->next->prev=NULL;
					//continue;
				else if(nn->prev!=NULL && nn->next!=NULL)
				nn->next->prev=nn->prev;
				
				if(f==0)
					res++;
				f=1;
				
			}
			nn=nn->prev;
				
		}
	//	printList(head);
		if(f==1)
		f=0;
		else if(f==0)
		break;
	}
	cout<<res;
        //cout << ' ' << s.front();
		//cout<<s.back();
    
}

		

	

