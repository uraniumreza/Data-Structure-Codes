#include <bits/stdc++.h>

using namespace std;

#define SWAP(a, b) int temp = a; a = b; b = temp;

void Heapify(int *a, int node, int length)
{
	int left, right, largest = node;
	left = 2*node + 1;
	right = 2*node + 2;

	if(a[node]<a[left] && left<=length) largest = left;
	if(a[largest]<a[right] && right<=length) largest = right;

	if(largest != node)
	{
		SWAP(a[largest], a[node]);
		Heapify(a, largest, length);
	}
}

void IncreaseKey(int *a, int node, int key)
{
	if(key<a[node]) cout<<"New Key is smaller than the current key"<<endl;
	else
	{
		a[node] = key;
		int z = floor((node-1)/2);
		while(node>0 && a[z]<a[node])
		{
			SWAP(a[node], a[z]);
			node = z;
			z = floor((node-1)/2);
		}
	}
}

void Insert(int *a, int key, int length)
{
	length++;
	a[length] = -1;
	IncreaseKey(a, length, key);
}

int Maximum(int *a)
{
	return a[0];
}

int ExtractMaximum(int *a, int length)
{
	if(length<0) cout<<"Heap Underflow"<<endl;
	int max = a[0];
	SWAP(a[0],a[length]);
	length--;
	Heapify(a, 0, length);
	return max;
}

void Display(int *a, int length)
{
	for(int i=0;i<=length;i++) cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	int n;
	int a[10000];
	int length = -1;
	while(1)
	{
		cout<<"1. Insert\n2. Show Maximum\n3. Extract Maximum\n4. Increase Value\n5. Display\n6. BREAK"<<endl;
		cout<<"Enter your Choice: "; cin>>n;

		if(n==1)
		{
			int p;
			cout<<"Enter Key: "; cin>>p;
			Insert(a, p, length);
			length++;
		}
		else if(n==2)
		{
			cout<<"Maximum Key: "<<Maximum(a)<<endl;
		}
		else if(n==3)
		{
			cout<<"Extracted Value: "<<ExtractMaximum(a, length)<<endl;
			length--;
		}
		else if(n==4)
		{
			int p, q;
			cout<<"Enter the node position: "; cin>>p;
			cout<<"Enter Key: "; cin>>q;
			IncreaseKey(a, p, q);
		}
		else if(n==5)
		{
			Display(a, length);
		}
		else if(n==6)
		{
			break;
		}
	}
	return 0;
}