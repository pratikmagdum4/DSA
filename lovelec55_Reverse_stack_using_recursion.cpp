#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int element)
{
    //base case
    if(s.empty())
    {
        s.push(element);
        return ;
    }

    int num = s.top();
    s.pop();

    //recursive call

    insertAtBottom(s,element);
    s.push(num);
}

void reverseStack(stack<int>&stack)
{
    //base case
    if(stack.empty())
    {
        return ;
    }

    int num = stack.top();

    stack.pop();

    //recursive call

    reverseStack(stack);

    insertAtBottom(stack,num);
}

void pop()
{
    
}

int main()
{
    stack<int>stack ;

    stack.push(34);
    stack.push(32);
    stack.push(8);
    stack.push(7);

    reverseStack(stack);
    stack.pop()<<endl;
//    cout<< stack.pop()<<endl;
//    cout<< stack.pop()<<endl;
//    cout<< stack.pop()<<endl;
  
}
