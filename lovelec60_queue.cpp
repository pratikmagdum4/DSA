#include<iostream>
#include<queue>
using namespace std;

int main()
{
    //create queue
    queue<int> q;

    q.push(12);
    cout<<"front of q is "<<q.front()<<endl;
    q.push(15);
    q.push(13);
    
    cout<<" size of queue is "<<q.size()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<"size of queue is "<<q.size()<<endl;;
    if(q.empty())
    {
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue is not empty"<<endl;
    }

}
