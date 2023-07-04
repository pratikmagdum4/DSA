#include<bits/stdc++.h>
using namespace std;


int kth_smallest(int arr[],int l,int r, int k)
{
    priority_queue<int>pq;

    //step1
    for(int i = 0; i<k; i++)
    {
        pq.push(arr[i]);
    }

    //step2
    for(int i = k; i<=r;i++)
    {
        if(arr[i]<pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans = pq.top();
    return ans;
}
int main()
{
   int arr[5] = {4,10,7,15,20};
   int ans = kth_smallest(arr,0,5,4);
    cout<<ans;
}