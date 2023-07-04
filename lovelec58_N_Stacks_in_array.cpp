#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Nstack{
    public:
        int *arr;
        int *top;
        int *next;

        int n,s;
        int freespot;

        public:

        //Initialize your data structure 
        Nstack(int N, int S)
        {

            n = N;
            s = S;

            arr = new int[s];
            next = new int[s];
            top = new int[n];

            //Initialise top with -1
            for(int i = 0; i<n; i++)
            {
                top[i] = -1;
            }

            //Initialize next values 
            for(int i = 0; i<s;i++)
            {
                next[i] = i+1;
            }
            //Initializing last index value with -1

            next[s-1] = -1;

            //Initializing freespot value with 0
            freespot = 0;
        }

        //Pushes  'X' into 'M'th stack. Returns true if it gets pushed into the stack ,and false otherwise 
        bool push(int x, int m)
        {
            //check for overflow
            if(freespot == -1)
            {
                return false;
            }

            //find index 
            int index = freespot;

            //update freespot
            freespot = next[index];

            //insert in array 
            arr[index] = x;

            //update next 
            next[index] = top[m-1];

            //update top
            top[m-1] = index;
            return true;
        }

        //Pops top element from Mth Stack. returns -1 if the stack is empty 

        int pop(int m)
        {
            //check underflow condition
            if(top[m-1] == -1)
            {
                return -1;
            }
            
            int index = top[m-1];

            top[m-1] = next[index];

            next[index] = freespot;

            freespot = index;
            
            return arr[index];
        }  
};
int main()
{

    int N = 3;
    int S = 6;

    Nstack s(N,S);


    for(int i = 0; i<S;i++)
    {
        s.arr[i] = -1;
    }


    s.push(24,1);
    s.push(24,1);
    s.push(24,1);
    s.push(24,2);   
    s.push(24,2);   
    s.push(24,2);   
    cout<<"poped element is"<<  s.pop(1)<<endl;
    cout<<"poped element is"<<s.pop(1)<<endl;
  cout<<"poped element is"<<  s.pop(1)<<endl;
    cout<<"poped element is"<<s.pop(2)<<endl;
    cout<<"poped element is"<<s.pop(2)<<endl;
   if(s.push(21,1))
        cout<<"possible"<<endl;
   else
        cout<<"not possible"<<endl;
   cout<<"poped element is"<< s.pop(2)<<endl;
   cout<<"poped element is"<< s.pop(2)<<endl;
   cout<<"poped element is"<< s.pop(2)<<endl;
   cout<<"poped element is"<< s.pop(2)<<endl;
    cout<<"poped element is"<<s.pop(2)<<endl;
    cout<<"poped element is"<<s.pop(2)<<endl;

    for(int i = 0;i<S;i++)
    {
        cout<<s.arr[i]<<" ";
    }
}