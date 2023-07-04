#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& stack,int count, int size)
{
    //base case
    if(count == size/2)
    {
        stack.pop();
        return;
    }
    int num = stack.top();
    stack.pop();

    //Recursive call

    solve(stack,count+1,size);
    stack.push(num);
}

void deleteMiddle(stack<int> & stack,int n){
    int count = 0;
    solve(stack, count , n);
}


int main()
{
    stack<int> stack ;
    stack.push(2);
    stack.push(4);
    stack.push(5);
    stack.push(1);
    stack.push(3);
   
    int size = 5;
    deleteMiddle(stack , size );
    cout<<stack.top()<<endl;
    stack.pop();
    cout<<stack.top()<<endl;
    stack.pop();
    cout<<stack.top()<<endl;
    stack.pop();
    cout<<stack.top()<<endl;
    stack.pop();


}