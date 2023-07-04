#include<iostream>
#include<stack>
#include<limits.h>
//#include<algorithms>
#include<vector>
using namespace std;

vector<int>nextSmallerElement(vector<int> & arr, int n)
{
    stack<int>s ;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1;i>=0;i--)
    {
        int curr = arr[i];
        while(s.top()>= curr)
        {
            s.pop();
        }

        //ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> a;

    a.push_back(2);
    a.push_back(1);
    a.push_back(5);
    a.push_back(6);
    a.push_back(2);
    a.push_back(3);

    vector<int>ans =  nextSmallerElement(a,6);
    for(int i= 0; i<6;i++)
    {
        cout<<ans[i]<<" ";
    }

}




