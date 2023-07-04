
#include<bits/stdc++.h>
using namespace std;

int kth_largest(int arr[],int n, int k)
{
    priority_queue<int,vector<int>,greater<int> >pq;
    for(int i = 0; i<k; i++)
    {
        pq.push(arr[i]);
    }

    for(int i = k; i<n;i++)
    {
        if(arr[i]>pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans =  pq.top();
    return ans;
}
int main()
{
    int arr[5] = {4,15,20,10,16};
    int ans  = kth_largest(arr,5,3);
    cout<<ans<<endl;
}