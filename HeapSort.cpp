#include <bits/stdc++.h>

using namespace std;

#define SWAP(a, b) int temp = a; a = b; b = temp;

void Heapify(int *a, int node, int length)
{
	int left, right, largest = node;
	left = 2*node + 1;
	right = 2*node + 2;

	if(a[node]<a[left] && left<length) largest = left;
	if(a[largest]<a[right] && right<length) largest = right;

	if(largest != node)
	{
		SWAP(a[largest], a[node]);
		Heapify(a, largest, length);
	}
}
void BuildHeap(int *a, int length)
{
	for(int i=floor(length/2)-1;i>=0;i--)
	{
		Heapify(a, i, length);
	}
} 
void HeapSort(int *a, int length)
{
	BuildHeap(a, length);
	int j = length - 1;
	for(int i=j; i>0; i--)
	{
		SWAP(a[i], a[0]);
		length--;
		Heapify(a, 0, length);
	}
}

int main()
{
	int a[1000];
	int length;

	cout<<"How many numbers: "; cin>>length;
	for(int i=0;i<length;i++) cin>>a[i];

	HeapSort(a, length);

	for(int i=0;i<length;i++) cout<<a[i]<<" ";
	cout<<endl;
}