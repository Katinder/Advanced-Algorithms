#include<iostream>
#include<cstdlib>
using namespace std;
int length=0;
int heapsize=0;

int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
int parent(int i)
{
	return i/2+1;
}
void heapify(int h[], int i)
{
	int smallest=i;
	int l=left(i);
	int r=right(i);
	
	if(h[smallest]>h[l] && l<length)	
    smallest=l;

	if(h[smallest]>h[r] && r<length)	
    smallest=r;
	
	if(smallest!=i)
	{
		int temp=h[i];
		h[i]=h[smallest];
		h[smallest]=temp;
		heapify(h,smallest);
	}
	
}

void build_minheap(int h[])
{
	for(int i=(length/2)-1;i>=0;i--)
	{
		heapify(h,i);
	}
}

int heap_minimum(int h[])
{
	return h[0];
}

int heap_extract_min(int h[])
{
	if (heapsize<0)
	{
		cout<<"\nERROR: Empty Queue";
		return 0;
	}
	
	int min=h[0];
	
	h[0]=h[heapsize-1];
	heapsize--;
	heapify(h,0);
	
	return min;
}

void heap_dec_key(int h[],int i,int key)
{
	if(key>h[i])
	{
		cout<<"\nERROR: Key cannot be increased";
		return;
	}
	
	h[i]=key;
	
	while(i>0 && h[parent(i)]>h[i])
	{
		int temp=h[parent(i)];
		h[parent(i)]=h[i];
		h[i]=h[parent(i)];
		i=parent(i);
	}	
}

void minheap_insert(int h[],int key)
{
	heapsize++;
	h[heapsize-1]=9999;
	heap_dec_key(h,heapsize-1,key);
}

int main()
{
	cout<<"Enter no of elements in heap: ";
	cin>>length;
	heapsize=length;
	
    //allocate extra space for extending size later
	int *h=(int *)malloc(2*length*sizeof(int));
	
	for(int i=0;i<length;i++) 
    cin>>*(h+i);
	
	cout<<"\nEntered elements: ";
	for(int j=0;j<length;j++) 
    cout<<*(h+j)<<" ";
	
	build_minheap(h);
	
	cout<<"\nMin-Heap: ";
	for(int j=0;j<length;j++) 
    cout<<*(h+j)<<" ";
	heapsize=length;
	
	int choice;
	cout<<"\n--------MENU--------\n";
	cout<<"HEAP-MINIMUM : 1\nHEAP-EXTRACT-MIN : 2\nHEAP-DECREASE-KEY : 3\nMIN-HEAP-INSERT : 4";
	
	int i,key=0;
	char c='y';
	while(c=='y')
	{
		cout<<"\nEnter choice of operation: ";
		cin>>choice;
	switch(choice)
	{
		case 1: cout<<"\nHeap Minimum: "<<heap_minimum(h);
				cout<<"\nPQ After Operation: ";
				for(int j=0;j<heapsize;j++) cout<<*(h+j)<<" ";
				break;
		case 2: cout<<"\nHeap Extract minimum"<<heap_extract_min(h);
				cout<<"\nPQ After Operation: ";
				for(int j=0;j<heapsize;j++) cout<<*(h+j)<<" ";
				break;
		case 3: cout<<"\nKey Change operation:";
				cout<<"\nEnter key to be changed: ";
				cin>>i;
				cout<<"\nEnter new key: ";
				cin>>key;
				heap_dec_key(h,i,key);
				cout<<"\nPQ After Operation: ";
				for(int j=0;j<heapsize;j++) cout<<*(h+j)<<" ";
				break;
		case 4: cout<<"\nEnter new element to be inserted: ";
				cin>>key;
				minheap_insert(h,key);
				cout<<"\nHeap After Operation: ";
				for(int j=0;j<heapsize;j++) cout<<*(h+j)<<" ";
				break;
		default: cout<<"\n\nERROR: Invalid Choice\n";
				break;
	}
	
	cout<<"\nEnter again?";
	cin>>c;
	}

}
