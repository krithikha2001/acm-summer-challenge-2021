#include <bits/stdc++.h>
using namespace std;
class Node
{
	public:
	Node* next;
	Node* prev;
	int v;
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<node->v<<" ";
        node = node->next;
    }
}
int main()
{
	Node* head=new Node();
//	Node* head=NULL;

	int n,q;
	cin>>n>>q;
	int data;
	//Node* n=head;
	cin>>data;
		//cout<<"D"<<head->v;

	head->v=data;

	head->next=NULL;
	head->prev=NULL;
	Node* nn=head;
	for(int i=1;i<n;i++)
	{
		cin>>data;
	Node* temp=new Node();

	temp->v=data;
	temp->next=NULL;
	temp->prev=NULL;
	//cout<<nn->v;
	nn->next=temp;
	temp->prev=nn;
		nn=nn->next;

	//	cin>>data;cout<<"as"<<data;
	//	insrt(&head,data);
	}
//	printList(head);

int o,l,r,d1,d2;
	Node* t=head;
	int p=0;
	while(q--)
	{
		cin>>o;
		if(o==1)
		{
			cin>>l;
			p-=l;
		}
		else if(o==2)
		{
			cin>>r;
			p+=r;
		}
		else if(o==3)
		{
			cin>>d1>>d2;
	//		cout<<p<<t->v<<"jbh\t";
			if(p>0)
			{
				p=abs(p);
				while(t!=NULL && p>0)
				{
				t=t->next;
				p--;
				}
			}
			else if(p<0)
			{
								p=abs(p);
 
				while(t!=NULL && p>0)
				{
				t=t->prev;
		//		cout<<"prev"<<t->v;
				p--;
				}
			}
			Node* curr=new Node();
			curr->v=d1;
			curr->prev=t;
			t->next->v=d2;
			t->next->prev=curr;
			curr->next=t->next;
			t->next=curr;
			//			cout<<p<<t->v<<"jbh\t";

		//	printList(head);
			p=0; 
					
		}
	}
 
	printList(head);
	
}
