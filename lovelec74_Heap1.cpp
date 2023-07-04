#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;


    public:
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size +1;
        int index = size;
        arr[index] = val;

        while(index > 1)
        {
            int parent = index/2;

            if(arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print()
    {
        for(int i = 1; i<= size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


    void deleteFromHeap()
    {
        if(size==0)
        {
            cout<<"Nothing to delete"<<endl;
        }

        //step 1:- put the last element into the first element
        arr[1] = arr[size];
        //step 2:- delete the last element
        size--;

        //step 3:- propogate root node to its right position
        int i = 1;
        while(i<size)
        {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex<size && arr[i] <arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex<size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }
};
int main()
{
    Heap h;
    h.insert(12);
    h.insert(13);
    h.insert(54);
    h.insert(16);
    h.insert(72);
    h.insert(18);
    h.insert(129);
    h.insert(123);
    h.insert(1243);
    h.insert(2);
    h.print();
    h.deleteFromHeap();
    h.print();

    return 0;


}
