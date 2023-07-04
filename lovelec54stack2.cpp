#include<iostream>
#include<stack>
using namespace std;


class Stack {
    //properties
    public:
    int *arr;
    int top;
    int size;

    public:
    //behaviour
    Stack(int size)
    {
        this-> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if(size - top >1)
        {
            top++;
            arr[top] = element;           
        }
        else{
            cout<<"stack overflow "<<endl;
        }
    }

    void pop()
    {
        if(top >= 0)
        {
            top--;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }

    int  peek()
    {
        if(top >= 0 && top<size)
        return arr[top];
        else{
            cout<<"Stack is empty "<<endl;
            return -1;
        }    
    }
    bool isEmpty()
    {
        if( top == -1)
        {
            return true;
        }
        else
        {
        return false;
        }
    }   

    bool isFull()
    {
        if(top == size-1)
        {
            return true;
        }
        else{
            return false;
        }
    }

    void display()
    {
        if(!isEmpty()){
            cout<<"Stack elements are"<<endl;
            for(int i = top;i>=0;i--)
            {
                cout<<arr[i]<<" ";  
            }
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
        cout<<endl;
    }
};
int main()
{

    Stack st(5);
    // st.push(22);
    // st.push(43);
    // st.push(56);
    // st.push(65);
    // st.push(68);

    // cout<< st.peek()<<endl;
    // st.pop();
    // cout<< st.peek()<<endl;
    // st.pop();
    // st.pop();
    // st.pop();
    // //st.pop(); 
    // cout<< st.peek()<<endl;
    if(st.isEmpty())
    {
        cout<<"The stack is empty "<<endl;
    }
    else{
        cout<<"The stack is not empty"<<endl;
    }

    while(1)
    {
        cout<<"1 for push\n2 for pop \n3 for display\n4 for peek element\n5 for exit"<<endl;

        int ch;
        cout<<"enter the choice"<<endl;
        cin>>ch;
        switch (ch)
        {
        case /* constant-expression */1:
                if(!st.isFull())
                {
                    int element;
                    cout<<"Enter the element"<<endl;
                    cin>>element;
                    st.push(element);
                }
                else{
                    cout<<"Stack is full "<<endl;
                }
            /* code */
            break;
        case 2:
                if(!st.isEmpty())
                { 
                    st.pop();
                }
                else{
                    cout<<"Stack is empty"<<endl;
                }
        break;
        case 3:
            if(!st.isEmpty())
            {
                st.display();
            }
            else{
                cout<<"Nothing to display"<<endl;
            }
            break;
        case 4:
            if(!st.isEmpty())
            {
                cout<<"The peek element is "<<st.peek()<<endl;
            }
            else{

                cout<<"Stack is empty"<<endl;
            }
            break;
        case 5:
            goto end;
            break;
        default:
            cout<<"Enter a valid choice"<<endl;
            break;
        }
    }
    end:
    return 0;
}