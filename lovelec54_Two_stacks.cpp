#include<iostream>
#include<stack>
using namespace std;


class TwoStack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    public:
    //Initialize Twostakes

    TwoStack(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr =new int[s];
    }
        //push in stack1
        void push1(int num) 
        {
            if(top1+1 < top2) 
            {
                top1++;
                arr[top1] = num;
            }
            else{
                cout<<"stack overflow"<<endl;
            }
        }

        //Push in stack 2
        void push2(int num)
        {
            if(top2-top1>1)
            {
                top2--;
                arr[top2] = num;
            }
            else{
                cout<<"stack overflow"<<endl;
            }
        }

        //Pop from stack1 & return popped element 
        int pop1()
        {
            if(top1==-1)
            {
                cout<<"stack underflow"<<endl;
                return -1;
            }
            else{
                int ans = arr[top1];
                top1--;
                return ans;
            }
        }

        //pop from stack 2 & return popped element

        int pop2()
        {
            if(top2<size)
            {
                int ans = arr[top2];
                top2++;
                return ans;
            }
            else{
                cout<<"stack underflow"<<endl;
                return -1;
            }
        }
        void peek1()
        {
            if(top1>1)
            {
                cout<<arr[top1]<<endl;
            }
        }
    
};


int main() {
    int size = 5;
    TwoStack s(size);
    
    // ts.push1(1);
    // ts.push2(2);
    // ts.push1(3);
    // ts.push2(4);
    // ts.push2(5); // stack overflow
    
    // cout << ts.pop1() << endl; // 3
    // cout << ts.pop2() << endl; // 4
    // cout << ts.pop1() << endl; // 1
    // cout << ts.pop2() << endl; // 2
    // cout << ts.pop2() << endl; // stack underflow
    s.push1(8);
    s.push1(4);
    s.push1(4);
    s.push1(4);
    s.push1(4);
    s.push1(4);

    cout<<s.pop1()<<endl;
    cout<<s.pop1()<<endl;
    cout<<s.pop1()<<endl;
    cout<<s.pop1()<<endl;
    cout<<s.pop1()<<endl;
  
    return 0;
}