#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<limits.h>//for INT_MIN ans INT_MAX

using namespace std;

class Solution{
    
    public:
vector<int>nextSmallerElement(vector<int>arr,int n)
{
    stack<int>s ;
    s.push(-1);
    vector<int>ans(n);

    for(int i= n-1; i>=0;i--)
    {
        int curr = arr[i];
        while(s.top()!= -1 && arr[s.top()]>= curr)
        {
            s.pop();
        }
        //ans is stack ka top 
        ans[i] = s.top();
        s.push(i);
        //cout<<"The next ans[i] is "<<ans[i]<<endl;
    }
    
    for(int i = 0;i<6;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return ans;
}
   
vector<int> prevSmallerElement(vector<int>arr,int n)
{
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    for(int  i = 0;i<n;i++)
    { 
        int curr = arr[i];
        while(s.top()!= -1 && arr[s.top()]>= curr)
        {
            s.pop();
        }
        //ans is stack ka top 
        ans[i] = s.top();
        s.push(i);
        //cout<<"The prev ans[i] is "<<ans[i]<<endl;
        
    }
    for(int i = 0;i<6;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return ans ;
}
public:
int largestRectangleArea(vector<int>& heights)
{
    int n= heights.size();

    vector<int>next(n);

    next = nextSmallerElement(heights,n);
    vector<int>prev(n);
    prev = prevSmallerElement(heights,n);

    int area = INT_MIN;
    for(int i = 0 ; i<n; i++)
    {
        int l = heights[i];
        if(next[i]==-1)
        {
            next[i]= n;
        }
        int b = next[i]-prev[i]-1;
        cout<<" value of next "<<next[i]<<endl;
        cout<<" value of prev "<<prev[i]<<endl;
        int newArea = l*b;
        area= max(area,newArea);
    }
    
    return area;
}
};
int main()
{

    Solution s;
   
    vector<int> heights;


    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);

    int ans = s.largestRectangleArea(heights);
    cout<<ans;
}















