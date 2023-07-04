#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;

    public:
    Heap(){
        size = 0;
    }

};
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i ;
    int right = 2*i +1;

    if(left<=n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while(size> 1)
    {
        //step 1: swap
        swap(arr[1], arr[size]);    
        size--;
        //step 2: root node at correct position
        heapify(arr,size,1);
    }

}

int main()
{
 int  arr[6] = {-1,3,4,5,6,6};
  //  Heap a;
   // a.insert(54);
   //creation of heap 
   int  n = 5; 
   for(int i = n/2; i>0; i--)
   {
        heapify(arr,n,i);
   }

    cout<<endl; 
    heapSort(arr,n);
    for(int i = 1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}