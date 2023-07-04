#include<iostream>
#include<queue>
using namespace std;

class Queue
{
            int *arr;
            int qfront;
            int rear;
            int size;

    public:

    Queue()
    {
        size = 100001;
        arr =new int[size];
        qfront = 0;
        rear = 0;
    }




    bool isEmpty()
    {
        if(qfront == rear)
        {
            return true;
        }
        else {
            return false;
        }
    }
    void enqueue(int data)
    {
        if(rear == size)
        {
            cout<<"queue is full "<<endl;
        }
        else{
            arr[rear] =data;
            rear++;
        }
    }

    int dequeue()
    {
        if(qfront == rear)
        {
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear)
            {
            qfront = 0;
            rear = 0;
            }
            return  ans;
        }
    }

    int front()
    {
            if(qfront == rear)
            {
                return -1;
            }
            else{
                return arr[qfront];
            }
    }
    void display()
    {
        if(qfront == rear)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        
        cout << "Queue elements: ";
        for(int i = qfront; i < rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    bool isFull()
    {
        if(qfront == 0 && rear == size-1)
        {
            return true;
        }
        else{
            return false;
        }
    }

};
int main()
{
    Queue q;
    // q.enqueue(21);
    // q.enqueue(213);
    // q.enqueue(212);
    // q.enqueue(21);
    // q.enqueue(21);
   // q.display();
    while(1)
    {
        cout<<"1 for enqueu\n2 for dequeue\n3 for display\n4 for exit"<<endl;
        int ch;
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch (ch)
        {
        case /* constant-expression */1:
            if(!q.isFull()){
                cout<<"enter the value"<<endl;
                int ele;
                cin>>ele;
                q.enqueue(ele);
            }
            else{
                cout<<"queue is full"<<endl;
            }
            /* code */
            break;
        case 2:
            if(!q.isEmpty())
            {
                q.dequeue();
            }
            else{
                cout<<"queue is empty"<<endl;
            }
            break;
        case 3:
            if(!q.isEmpty())
            {
                q.display();
            }
            else{
                cout<<"Nothing to dispaly"<<endl;
            }
            break;
        case 4:
            goto end;   
        default:
            cout<<"Enter a valid choice"<<endl;
            break;
        }
    }
    end:
    return 0;
}


































































