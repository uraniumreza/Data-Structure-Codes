#include <bits/stdc++.h>
using namespace std;

class MinHeap {
	int SIZE;
	int* mH;
	int position;

	MinHeap(int SIZE){
		this.SIZE = SIZE;
		mH = new int [SIZE+1];
		position = 0;
	}

	void createHeap(int arrA[]){
		if(arrA.length>0){
			for(int i=0;i<arrA.length;i++){
				Insert(arrA[i]);
			}
		}
	}
	void display(){
		for(int i=1;i<mH.length;i++){
			System.out.print(" " + mH[i]);
		}
		System.out.println("");
	}
	void Insert(int x){
		if(position==0){
			mH[position+1]=x;
			position = 2;
		}else{
			mH[position++]=x;
			bubbleUp();
		}
	}
	void bubbleUp(){
		int pos = position-1;
		while(pos>0 && mH[pos/2]>mH[pos]){
			int y = mH[pos];
			mH[pos]=mH[pos/2];
			mH[pos/2] = y;
			pos = pos/2;
		}
	}
	int extractMin(){
		int min = mH[1];
		mH[1]=mH[position-1];
		mH[position-1]=0;
		position--;
		sinkDown(1);
		return min;
	}

	void sinkDown(int k){int a = mH[k];
		int smallest =k;
		if(2*k<position && mH[smallest]>mH[2*k]){
			smallest = 2*k;
		}
		if(2*k+1<position && mH[smallest]>mH[2*k+1]){
			smallest = 2*k+1;
		}
		if(smallest!=k){
			swap(k,smallest);
			sinkDown(smallest);
		}

	}
	void swap(int a, int b){
		//System.out.println("swappinh" + mH[a] + " and " + mH[b]);
		int temp = mH[a];
		mH[a] = mH[b];
		mH[b] = temp;
	}

	void main(String args[]){
		int arrA [] = {3,2,1,7,8,4,10,16,12};
		System.out.print("Original Array : ");
		for(int i=0;i<arrA.length;i++){
			System.out.print("  " + arrA[i]);
		}
		minHeap m = new minHeap(arrA.length);
		System.out.print("\nMin-Heap : ");
		m.createHeap(arrA);
		m.display();
		System.out.print("Extract Min :");
		for(int i=0;i<arrA.length;i++){
			System.out.print("  " + m.extractMin());
		}

	}
}

int main(){


    return 0;
}


