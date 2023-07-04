#include<iostream>
#include<queue>
using namespace std;
int main()
{   
    queue<int>q;
    //create queue
    q.push(7);
    q.push(3);
    cout<<"front of queue is "<<q.front()<<endl;
    q.push(4);
    q.push(2);
    cout<<"front of queue is "<<q.front()<<endl;
    q.push(1);
    q.push(8);
    cout<<"front of queue is "<<q.front()<<endl;
    cout<<"the size of queue is "<<q.size()<<endl;
    q.pop();
    cout<<"the size of queue is "<<q.size()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
   
    cout<<"the size of queue is "<<q.size()<<endl;
    if(q.empty())
    {
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue is not empty"<<endl;
    }
}