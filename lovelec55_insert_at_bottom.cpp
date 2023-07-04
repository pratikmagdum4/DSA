#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int x)
{
    //base case
    if(s.empty())
    {
        s.push(x);
        return ;
    }


    int num = s.top();
    s.pop();

    //recursive call

    solve(s,x);
    s.push(num);

}

stack <int> pushAtBottom(stack<int>& s, int x)
{
    solve(s,x);
    return s;
}
int main()
{
    stack<int>s;
    int x = 5;
    s.push(6);
    s.push(8);
    s.push(4);
    s.push(3);
    s.push(9);
   // s.push(12);

    pushAtBottom(s,x);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();

}





