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

/*
#include <bits/stdc++.h>
using namespace std;

long long getSum(long long BITree[], long long index)
{
	long long sum = 0; 

	while (index > 0)
	{
		sum += BITree[index];
		index -= index & (-index);
	}
	return sum;
}


void updateBIT(long long BITree[], long long n, long long index, long long val)
{
	while (index <= n)
	{
	BITree[index] += val;

	index += index & (-index);
	}
}

long long inv(long long arr[], int n)
{
	long long invcount = 0; 

	long long* maxElement;
	maxElement = std::max_element(arr, arr + n);
	////for (int i=0; i<n; i++)
	//	if (maxElement < arr[i])
	//		maxElement = arr[i];

	long long BIT[*maxElement+1];
	for (int i=1; i<=*maxElement; i++)
		BIT[i] = 0;

	for (int i=n-1; i>=0; i--)
	{
		invcount += getSum(BIT, arr[i]-1);
		updateBIT(BIT, *maxElement, arr[i], 1);
	}

	return invcount;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	int q;
	cin >>n>>q;
	long long *arr;
	arr=(long long *) malloc(n*sizeof(long long));
	//int arr[n];
//	vector<int> arr(n);
//	int tp;
	for(int i=0;i<n;i++)
		{
			cin>>arr[i];
	//		brr[i]=arr[i];
		}
	
	//	mergeSort(brr,0,n-1);
	int base=inv(arr,n);
//	cout<<base;
;
	int a,b,t1,bs;
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
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}//				cout<<"dec"<<bs;

		for(int j=a-1;j<n;j++)
		{
			if(arr[a-1]>arr[j])
			{
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}				//cout<<"dec"<<bs;

		for(int j=0;j<b-1;j++)
		{
			if(arr[b-1]<arr[j] && j!=a-1)
			{
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=b-1;j<n;j++)
		{
			if(arr[b-1]>arr[j]  && j!=a-1)
			{
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}		//		cout<<"dec"<<bs;

			   // vector< pair <int,int> > vect2=vect;
	//	for(int i=0;i<vect.size();i++)
	//	{
	//		if(vect[i].first==a-1||vect[i].second==a-1|| vect[i].first==b-1 || vect[i].second==b-1)
	//		{	
			//	vect2.erase(vext2.begin()+i);
	//			bs--;
	//		}
	//	}
	//	for(int i=0;i<b-1;i++)
	//		if(arr[b-1]<arr[i])
	//			bs--;
			//	cout<<"dec"<<bs;
		t1=arr[a-1]+arr[b-1];
	//	t2=arr[b-1];
		arr[a-1]=arr[b-1];
		arr[b-1]=t1-arr[a-1];
	//	cout<<"\t"<<a-1<<b-1;
		for(int j=0;j<a-1;j++)
		{
			if(arr[a-1]<arr[j])
			{
			       // vect.push_back( make_pair(i,j) );
					bs++;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=a-1;j<n;j++)
		{
			if(arr[a-1]>arr[j])
			{
			       // vect.push_back( make_pair(i,j) );
					bs++;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=0;j<b-1;j++)
		{
			if(arr[b-1]<arr[j] && j!=a-1)
			{
			       // vect.push_back( make_pair(i,j) );
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
	//	for(int i=0;i<n;i++)
	//	brr[i]=arr[i];
	//	cout<<inv(arr)<<"\n";
	  //  cout << inv << "\n";
	//	inv=0;
		
	//	cout<<temp<<r<<"\n";
	
		arr[a-1]=arr[b-1];
		arr[b-1]=t1-arr[a-1];
	}
	return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
int inv(vector<int>& nums) {
      //  vector<int> result(nums.size()),
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
//	int *arr;
//	arr=(int *) malloc(n*sizeof(int));
	//int arr[n];
	vector<int> arr(n);
//	int tp;
	for(int i=0;i<n;i++)
		{
			cin>>arr[i];
	//		brr[i]=arr[i];
		}
	//	cout<<"99"<<arr[99]<<"199"<<arr[199]<<"999"<<arr[999];
	
	//	mergeSort(brr,0,n-1);
//	int base=inv(arr);
//	cout<<base;
//	int base=0;
//	vector< pair <int,int> > vect;
//	for(int i=0;i<arr.size();i++)
//	{
//	cin>>arr[i];
//	for(int j=i+1;j<arr.size();j++)
//	{
//		if(arr[j]<arr[i])
//		{
//			        vect.push_back( make_pair(i,j) );
//			        cout<<i<<j;
//					base++;
//		}
//	}
//	}
//	ll base=inv(arr);
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
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}//				cout<<"dec"<<bs;

		for(int j=a-1;j<n;j++)
		{
			if(arr[a-1]>arr[j])
			{
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}				//cout<<"dec"<<bs;

		for(int j=0;j<b-1;j++)
		{
			if(arr[b-1]<arr[j] && j!=a-1)
			{
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=b-1;j<n;j++)
		{
			if(arr[b-1]>arr[j]  && j!=a-1)
			{
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}		//		cout<<"dec"<<bs;

			   // vector< pair <int,int> > vect2=vect;
	//	for(int i=0;i<vect.size();i++)
	//	{
	//		if(vect[i].first==a-1||vect[i].second==a-1|| vect[i].first==b-1 || vect[i].second==b-1)
	//		{	
			//	vect2.erase(vext2.begin()+i);
	//			bs--;
	//		}
	//	}
	//	for(int i=0;i<b-1;i++)
	//		if(arr[b-1]<arr[i])
	//			bs--;
			//	cout<<"dec"<<bs;
		t1=arr[a-1];
		t2=arr[b-1];
		arr[a-1]=arr[b-1];
		arr[b-1]=t1;
	//	cout<<"\t"<<a-1<<b-1;
		for(int j=0;j<a-1;j++)
		{
			if(arr[a-1]<arr[j])
			{
			       // vect.push_back( make_pair(i,j) );
					bs++;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=a-1;j<n;j++)
		{
			if(arr[a-1]>arr[j])
			{
			       // vect.push_back( make_pair(i,j) );
					bs++;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=0;j<b-1;j++)
		{
			if(arr[b-1]<arr[j] && j!=a-1)
			{
			       // vect.push_back( make_pair(i,j) );
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
	//	for(int i=0;i<n;i++)
	//	brr[i]=arr[i];
	//	cout<<inv(arr)<<"\n";
	  //  cout << inv << "\n";
	//	inv=0;
		
	//	cout<<temp<<r<<"\n";
	
		arr[a-1]=t1;
		arr[b-1]=t2;
	}
	return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
int base=0; 

void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	
	int i = 0;

	int j = 0;

	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
			base+=n1-i;
		}
		k++;
	}


	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[],int l,int r){
	if(l>=r){
		return;
	}
	int m =l+ (r-l)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	int q;
	cin >>n>>q;
//	int *arr;
//	arr=(int *) malloc(n*sizeof(int));
	int arr[n],brr[n];
//	int tp;
	for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			brr[i]=arr[i];
		}
		mergeSort(brr,0,n-1);
//	int base=inv(arr,n);
//	cout<<base;
//	int base=0;
//	vector< pair <int,int> > vect;
//	for(int i=0;i<arr.size();i++)
//	{
//	cin>>arr[i];
//	for(int j=i+1;j<arr.size();j++)
//	{
//		if(arr[j]<arr[i])
//		{
//			        vect.push_back( make_pair(i,j) );
//			        cout<<i<<j;
//					base++;
//		}
//	}
//	}
//	ll base=inv(arr);
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
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}//				cout<<"dec"<<bs;

		for(int j=a-1;j<n;j++)
		{
			if(arr[a-1]>arr[j])
			{
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}				//cout<<"dec"<<bs;

		for(int j=0;j<b-1;j++)
		{
			if(arr[b-1]<arr[j] && j!=a-1)
			{
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=b-1;j<n;j++)
		{
			if(arr[b-1]>arr[j]  && j!=a-1)
			{
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}		//		cout<<"dec"<<bs;

			   // vector< pair <int,int> > vect2=vect;
	//	for(int i=0;i<vect.size();i++)
	//	{
	//		if(vect[i].first==a-1||vect[i].second==a-1|| vect[i].first==b-1 || vect[i].second==b-1)
	//		{	
			//	vect2.erase(vext2.begin()+i);
	//			bs--;
	//		}
	//	}
	//	for(int i=0;i<b-1;i++)
	//		if(arr[b-1]<arr[i])
	//			bs--;
			//	cout<<"dec"<<bs;
		t1=arr[a-1];
		t2=arr[b-1];
		arr[a-1]=arr[b-1];
		arr[b-1]=t1;
	//	cout<<"\t"<<a-1<<b-1;
		for(int j=0;j<a-1;j++)
		{
			if(arr[a-1]<arr[j])
			{
			       // vect.push_back( make_pair(i,j) );
					bs++;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=a-1;j<n;j++)
		{
			if(arr[a-1]>arr[j])
			{
			       // vect.push_back( make_pair(i,j) );
					bs++;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=0;j<b-1;j++)
		{
			if(arr[b-1]<arr[j] && j!=a-1)
			{
			       // vect.push_back( make_pair(i,j) );
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
	//	for(int i=0;i<n;i++)
	//	brr[i]=arr[i];
	//	cout<<inv(arr)<<"\n";
	  //  cout << inv << "\n";
	//	inv=0;
		
	//	cout<<temp<<r<<"\n";
	
		arr[a-1]=t1;
		arr[b-1]=t2;
	}
	return 0;
}*/
/*#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int inv(vector<int>& nums) {
      //  vector<int> result(nums.size()),
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
//	int *arr;
//	arr=(int *) malloc(n*sizeof(int));
	vector <int> arr(n);
//	int tp;
	for(int i=0;i<n;i++)
		cin>>arr[i];
//	int base=0;
//	vector< pair <int,int> > vect;
//	for(int i=0;i<arr.size();i++)
//	{
//	cin>>arr[i];
//	for(int j=i+1;j<arr.size();j++)
//	{
//		if(arr[j]<arr[i])
//		{
//			        vect.push_back( make_pair(i,j) );
//			        cout<<i<<j;
//					base++;
//		}
//	}
//	}
	int base=inv(arr);
		while(q--)
	{
		int a,b,t1,t2,bs=base;
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
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}//				cout<<"dec"<<bs;

		for(int j=a-1;j<n;j++)
		{
			if(arr[a-1]>arr[j])
			{
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}				//cout<<"dec"<<bs;

		for(int j=0;j<b-1;j++)
		{
			if(arr[b-1]<arr[j] && j!=a-1)
			{
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=b-1;j<n;j++)
		{
			if(arr[b-1]>arr[j]  && j!=a-1)
			{
			       // vect.push_back( make_pair(i,j) );
					bs--;
			}
		}		//		cout<<"dec"<<bs;

			   // vector< pair <int,int> > vect2=vect;
	//	for(int i=0;i<vect.size();i++)
	//	{
	//		if(vect[i].first==a-1||vect[i].second==a-1|| vect[i].first==b-1 || vect[i].second==b-1)
	//		{	
			//	vect2.erase(vext2.begin()+i);
	//			bs--;
	//		}
	//	}
	//	for(int i=0;i<b-1;i++)
	//		if(arr[b-1]<arr[i])
	//			bs--;
			//	cout<<"dec"<<bs;
		t1=arr[a-1];
		t2=arr[b-1];
		arr[a-1]=arr[b-1];
		arr[b-1]=t1;
	//	cout<<"\t"<<a-1<<b-1;
		for(int j=0;j<a-1;j++)
		{
			if(arr[a-1]<arr[j])
			{
			       // vect.push_back( make_pair(i,j) );
					bs++;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=a-1;j<n;j++)
		{
			if(arr[a-1]>arr[j])
			{
			       // vect.push_back( make_pair(i,j) );
					bs++;
			}
		}			//	cout<<"dec"<<bs;

		for(int j=0;j<b-1;j++)
		{
			if(arr[b-1]<arr[j] && j!=a-1)
			{
			       // vect.push_back( make_pair(i,j) );
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
	//	for(int i=0;i<n;i++)
	//	brr[i]=arr[i];
	//	cout<<inv(arr)<<"\n";
	  //  cout << inv << "\n";
	//	inv=0;
		
	//	cout<<temp<<r<<"\n";
	
		arr[a-1]=t1;
		arr[b-1]=t2;
	}
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key, height;
	struct Node *left, *right;

	int size;
};


int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}


int size(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->size;
}

struct Node* newNode(int key)
{
	struct Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	node->height = node->size = 1;
	return(node);
}

struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	y->height = max(height(y->left),
height(y->right))+1;
	x->height = max(height(x->left),
height(x->right))+1;

	y->size = size(y->left) + size(y->right) + 1;
	x->size = size(x->left) + size(x->right) + 1;

	return x;
}

struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	x->size = size(x->left) + size(x->right) + 1;
	y->size = size(y->left) + size(y->right) + 1;

	return y;
}

int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}


struct Node* insert(struct Node* node, int key, int *result)
{
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
	{
		node->left = insert(node->left, key, result);

		*result = *result + size(node->right) + 1;
	}
	else
		node->right = insert(node->right, key, result);

	node->height = max(height(node->left),
					height(node->right)) + 1;
	node->size = size(node->left) + size(node->right) + 1;


	int balance = getBalance(node);



	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

int inv(int arr[], int n)
{
struct Node *root = NULL; 

int result = 0; 
for (int i=0; i<n; i++)

	root = insert(root, arr[i], &result);

return result;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	int q;
	cin >> n>>q;
	int *arr;
	arr=(int *) malloc(n*sizeof(int));

	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int base=inv(arr,n);
		while(q--)
	{
		int a,b,t1,t2;
		cin>>a>>b;
		if(a==b)
		{
			cout<<base<<"\n";
			continue;
		}
		t1=arr[a-1];
		t2=arr[b-1];
		arr[a-1]=arr[b-1];
		arr[b-1]=t1;
	//	for(int i=0;i<n;i++)
	//	brr[i]=arr[i];
		cout<<inv(arr,n)<<"\n";
	  //  cout << inv << "\n";
	//	inv=0;
		
	//	cout<<temp<<r<<"\n";
	
		arr[a-1]=t1;
		arr[b-1]=t2;
	}
	return 0;
}

/*#include <iostream>
using namespace std;

struct Node {
	int count;
	Node* left;
	Node* right;
};


Node* makeNewNode()
{
	Node* temp = new Node;
	temp->count = 1;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insertElement(int num,
				Node* root,
				int& ans)
{

	for (int i = 63; i >= 0; i--) {
	
		int a = (num & (1 << i));
		if (a != 0) {
		
			if (root->left != NULL)
				ans += root->left->count;

	
			if (root->right != NULL) {
				root = root->right;
				root->count += 1;
			}

			else {
				Node* temp = makeNewNode();
				root->right = temp;
				root = root->right;
			}
		}

		else {

			if (root->left != NULL) {
				root = root->left;
				root->count++;
			}

	
			else {
				Node* temp = makeNewNode();
				root->left = temp;
				root = root->left;
			}
		}
	}
}


int inv(int arr[], int n)
{
	Node* head = makeNewNode();
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		insertElement(arr[i],head,ans);
	}

	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	int q;
	cin >> n>>q;
	int *arr;
	arr=(int *) malloc(n*sizeof(int));

	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int base=inv(arr,n);
		while(q--)
	{
		int a,b,t1,t2;
		cin>>a>>b;
		if(a==b)
		{
			cout<<base<<"\n";
			continue;
		}
		t1=arr[a-1];
		t2=arr[b-1];
		arr[a-1]=arr[b-1];
		arr[b-1]=t1;
	//	for(int i=0;i<n;i++)
	//	brr[i]=arr[i];
		cout<<inv(arr,n)<<"\n";
	  //  cout << inv << "\n";
	//	inv=0;
		
	//	cout<<temp<<r<<"\n";
	
		arr[a-1]=t1;
		arr[b-1]=t2;
	}
	return 0;
}

/*#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll getSum(ll BITree[], ll index)
{
	ll sum = 0; 

	while (index > 0)
	{
		sum += BITree[index];
		index -= index & (-index);
	}
	return sum;
}

void updateBIT(ll BITree[], ll n, ll index, ll val)
{
	while (index <= n)
	{
	BITree[index] += val;
	index += index & (-index);
	}
}


void convert(ll arr[], ll n)
{

	ll temp[n];
	for (int i=0; i<n; i++)
		temp[i] = arr[i];
	sort(temp, temp+n);
	for (int i=0; i<n; i++)
	{
		arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
	}
}

ll inv(ll arr[], ll n)
{
	ll invcount = 0; 
	convert(arr, n);


	ll BIT[n+1];
	for (ll i=1; i<=n; i++)
		BIT[i] = 0;

	for (ll i=n-1; i>=0; i--)
	{
		invcount += getSum(BIT, arr[i]-1);
		updateBIT(BIT, n, arr[i], 1);
	}

	return invcount;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	long long q;
	cin >> n>>q;
	long long int *arr;
	arr=(long long int *) malloc(n*sizeof(long long int));

	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	long long base=inv(arr,n);
		while(q--)
	{
		long long a,b,t1,t2;
		cin>>a>>b;
		if(a==b)
		{
			cout<<base<<"\n";
			continue;
		}
		t1=arr[a-1];
		t2=arr[b-1];
		arr[a-1]=arr[b-1];
		arr[b-1]=t1;
	//	for(int i=0;i<n;i++)
	//	brr[i]=arr[i];
		cout<<inv(arr,n)<<"\n";
	  //  cout << inv << "\n";
	//	inv=0;
		
	//	cout<<temp<<r<<"\n";
	
		arr[a-1]=t1;
		arr[b-1]=t2;
	}
	return 0;
}
/*#include <bits/stdc++.h>
using namespace std;


long long getSum(long long BITree[], long long index)
{
	long long sum = 0; 

	while (index > 0)
	{
		sum += BITree[index];
		index -= index & (-index);
	}
	return sum;
}


void updateBIT(long long BITree[], long long n, long long index, long long val)
{
	while (index <= n)
	{
	BITree[index] += val;

	index += index & (-index);
	}
}

long long inv(long long arr[], int n)
{
	long long invcount = 0; 

	long long* maxElement;
	maxElement = std::max_element(arr, arr + n);
	////for (int i=0; i<n; i++)
	//	if (maxElement < arr[i])
	//		maxElement = arr[i];

	long long BIT[*maxElement+1];
	for (int i=1; i<=*maxElement; i++)
		BIT[i] = 0;

	for (int i=n-1; i>=0; i--)
	{
		invcount += getSum(BIT, arr[i]-1);
		updateBIT(BIT, *maxElement, arr[i], 1);
	}

	return invcount;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	long long q;
	cin >> n>>q;
	long long int *arr;
	arr=(long long int *) malloc(n*sizeof(long long int));

	for(int i=0;i<n;i++)
		cin>>arr[i];
	int mem[n][n];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	mem[i][j]=-1;
	//fill(mem, mem+sizeof(mem), -1); 
//memset(mem[0][0],-1,sizeof(mem));

//fill( &mem[0][0], &mem[0][0] + sizeof(mem), -1 );

	//std::fill_n(mem, n, -1);

//	int r=0;
	long long base=inv(arr,n);
		while(q--)
	{
		long long a,b,t1,t2;
		cin>>a>>b;
		if(a==b)
		{
			cout<<base<<"\n";
			continue;
		}
		if(mem[a][b]==-1)
		{
		t1=arr[a-1];
		t2=arr[b-1];
		arr[a-1]=arr[b-1];
		arr[b-1]=t1;
	//	for(int i=0;i<n;i++)
	
	//	brr[i]=arr[i];
		cout<<inv(arr,n)<<"\n";
		mem[a][b]=inv(arr,n);
		mem[b][a]=mem[a][b];
		cout<<mem[a][b]<<"\n";
	  //  cout << inv << "\n";
	//	inv=0;
		
	//	cout<<temp<<r<<"\n";
		arr[a-1]=t1;
		arr[b-1]=t2;
		continue;
		}
		else
		{
			cout<<mem[a][b]<<"\n";
			continue;
		}
	}
	return 0;
}*/
/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	ll q;
	cin >> n>>q;
	//ll arr[n];
	vector<pair<ll,int>> arr;
	for(int i=1;i<=n;i++)
	        vect.push_back( make_pair(arr[i],i) );
	//cin>>arr[i];
		while(q--)
	{
		ll a,b,t1,t2,r=0;
		cin>>a>>b;
		t1=arr[a].first;
		t2=arr[b].first;
		arr[a].first=arr[b].first;
		arr[b].first=t1;
		
	//	for(int i=0;i<n;i++)
	//	brr[i]=arr[i];
	//	cout<<inv(arr,n)<<"\n";
	  //  cout << inv << "\n";
	//	inv=0;
		
	//	cout<<temp<<r<<"\n";
		arr[a].first=t1;
		arr[b].first=t2;
	}
}*/
/*
#include<bits/stdc++.h>
using namespace std;


long long getSum(long long BITree[], long long index)
{
	long long sum = 0; 

	while (index > 0)
	{
		sum += BITree[index];
		index -= index & (-index);
	}
	return sum;
}


void updateBIT(long long BITree[], long long n, long long index, long long val)
{
	while (index <= n)
	{
	BITree[index] += val;

	index += index & (-index);
	}
}

long long inv(long long arr[], int n)
{
	long long invcount = 0; 

	long long* maxElement;
	maxElement = std::max_element(arr, arr + n);
	////for (int i=0; i<n; i++)
	//	if (maxElement < arr[i])
	//		maxElement = arr[i];

	long long BIT[*maxElement+1];
	for (int i=1; i<=*maxElement; i++)
		BIT[i] = 0;

	for (int i=n-1; i>=0; i--)
	{
		invcount += getSum(BIT, arr[i]-1);
		updateBIT(BIT, *maxElement, arr[i], 1);
	}

	return invcount;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	long long q;
	cin >> n>>q;
	long long arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
		while(q--)
	{
		long long a,b,t1,t2,r=0;
		cin>>a>>b;
		t1=arr[a-1];
		t2=arr[b-1];
		arr[a-1]=arr[b-1];
		arr[b-1]=t1;
	//	for(int i=0;i<n;i++)
	//	brr[i]=arr[i];
		cout<<inv(arr,n)<<"\n";
	  //  cout << inv << "\n";
	//	inv=0;
		
	//	cout<<temp<<r<<"\n";
		arr[a-1]=t1;
		arr[b-1]=t2;
	}
	return 0;
}*/
/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int inv(ll arr[],int n)
{
    multiset<ll> set1;
    set1.insert(arr[0]);
  
    int invcount = 0; 
  
    multiset<ll>::iterator it; 
	for (int i=1; i<n; i++)
    {

        set1.insert(arr[i]);
        it = set1.upper_bound(arr[i]);
        invcount += distance(it, set1.end());
    }
  
    return invcount;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	ll q;
	cin >> n>>q;
	ll arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
		while(q--)
	{
		ll a,b,t1,t2,r=0;
		cin>>a>>b;
		t1=arr[a-1];
		t2=arr[b-1];
		arr[a-1]=arr[b-1];
		arr[b-1]=t1;
	//	for(int i=0;i<n;i++)
	//	brr[i]=arr[i];
		cout<<inv(arr,n)<<"\n";
	  //  cout << inv << "\n";
	//	inv=0;
		
	//	cout<<temp<<r<<"\n";
		arr[a-1]=t1;
		arr[b-1]=t2;
	}
}*/

/*
#include<bits/stdc++.h>
using namespace std;
  
int inv(int arr[],int n)
{
    multiset<int> set1;
    set1.insert(arr[0]);
  
    int invcount = 0; 
  
    multiset<int>::iterator it; 
	for (int i=1; i<n; i++)
    {

        set1.insert(arr[i]);
  
        
        it = set1.upper_bound(arr[i]);
  
 
        invcount += distance(it, set1.end());
    }
  
    return invcount;
}

int main(){
    int n,q;
	cin >> n>>q;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
		while(q--)
	{
		int a,b,t1,t2,r=0;
		cin>>a>>b;
		t1=arr[a-1];
		t2=arr[b-1];
		arr[a-1]=arr[b-1];
		arr[b-1]=t1;
	//	for(int i=0;i<n;i++)
	//	brr[i]=arr[i];
		cout<<inv(arr,n)<<"\n";
	  //  cout << inv << "\n";
	//	inv=0;
		
	//	cout<<temp<<r<<"\n";
		arr[a-1]=t1;
		arr[b-1]=t2;
	}
}
/*
#include <iostream>
using namespace std;
int inv=0;

void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	
	int i = 0;

	int j = 0;

	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
			inv+=n1-i;
		}
		k++;
	}


	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[],int l,int r){
	if(l>=r){
		return;
	}
	int m =l+ (r-l)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}


int main(){
    int n,q;
	cin >> n>>q;
	int arr[n],brr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
		while(q--)
	{
		int a,b,t1,t2,r=0;
		cin>>a>>b;
		t1=arr[a-1];
		t2=arr[b-1];
		arr[a-1]=arr[b-1];
		arr[b-1]=t1;
		for(int i=0;i<n;i++)
		brr[i]=arr[i];
		mergeSort(brr,0,n-1);
	    cout << inv << "\n";
		inv=0;
		
	//	cout<<temp<<r<<"\n";
		arr[a-1]=t1;
		arr[b-1]=t2;
	}
}*/
