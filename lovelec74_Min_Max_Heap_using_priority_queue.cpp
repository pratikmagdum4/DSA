#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;
    public:
    Heap()
    {
        size = 0; 
    }

};
int main()
{
    //Max Heap
    priority_queue<int> pq;
    pq.push(7);
    pq.push(8);
    pq.push(1);
    pq.push(4);
    pq.push(3);
    cout<<"Top element is "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element is "<<pq.top()<<endl;
    if(pq.empty())
    {
        cout<<"It is empty"<<endl;
    }
    else{
        cout<<"It is not empty"<<endl;
    }

    //Min Heap
    priority_queue<int , vector<int>, greater<int> > minheap;
    minheap.push(34);
    minheap.push(54);
    minheap.push(24);
    minheap.push(14);
    minheap.push(94);
    cout<<"Top element is "<<minheap.top()<<endl;
    cout<<"size is "<<minheap.size()<<endl;
}