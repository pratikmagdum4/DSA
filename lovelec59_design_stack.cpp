#include<iostream>
#include<stack>
#include<limits.h>

using namespace std;

class SpecialStack {
        //define data members
        stack<int>s;
        int mini = INT_MAX;

        public:


        void push(int data)
        {
            //for first element
            if(s.empty())
            {
                s.push(data);
                mini = data;
            }
            else{
                if(data<mini)
                {
                    s.push(2*data - mini);
                    mini = data;
                }
                else{
                    s.push(data);
                }
            }
        }
        int pop()
        {
            if(s.empty())
            {
                return -1;
            }


            int curr  = s.top();
            s.pop();
            if(curr >mini)
            {
                return curr;
            }
            else{
                int prevmini = mini;
                int val = 2* mini - curr;
                mini = val;
                return prevmini;
            }
        }
        int top()
        {
            if(s.empty())
                return -1;

            int curr = s.top();
            if(curr<mini)
            {
                return mini;
            }
            else{
                return curr;
            }
        }

        bool isEmpty()
        {
            return s.empty();
        }
        int getMin()
        {
            if(s.empty())
            {
                return -1;
            }

            return mini;
        }
};

//#include "SpecialStack.h"

int main() {
    SpecialStack s;

    // Push some elements onto the stack
    s.push(3);
    s.push(5);
    s.push(2);
    s.push(1);

    // Print the top element of the stack
    std::cout << "Top: " << s.top() << std::endl;

    // Print the minimum element in the stack
    std::cout << "Minimum: " << s.getMin() << std::endl;

    // Pop some elements from the stack
    s.pop();
    s.pop();

    // Print the top element of the stack after popping
    std::cout << "Top: " << s.top() << std::endl;

    // Print the minimum element in the stack after popping
    std::cout << "Minimum: " << s.getMin() << std::endl;

    return 0;
}
