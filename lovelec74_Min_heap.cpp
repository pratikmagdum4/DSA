#include<iostream>
//#include<bits/stdc++.h>
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
    void insert(int val)
    {
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index>1)
        {
            int parent = index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    void print()
    {
        for(int i = 1; i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void heapify(vector<int> &arr, int n, int i )
{
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[smallest]>arr[left])
    {
        smallest = left;
    }
    if(right<n && arr[smallest]>arr[right])
    {
        smallest = right;
    }

    if(smallest != i)
    {
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}
void buildMinHeap(vector<int> & arr)
{
    int n = arr.size();
    for(int i = n/2-1;i>=0; i--)
    {
        heapify(arr,n,i);
    }
    //return arr; 
}

int main()
{
    vector<int> arr = {78,54,4,56,65,34};
    int n = 6;
    // for(int i = n/2;i>0;i--)
    // {
    //     heapify(arr,n,i);
    // }
    //vector<int>ans = buildMinHeap(arr);
    buildMinHeap(arr);
    cout<<"printing the array now"<<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}