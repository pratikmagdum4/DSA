#include<iostream>
#include<stack>
using namespace std;

bool isValidPalindrome(string expression)
{
    stack<char>s;
    for(int i = 0 ; i<expression.length();i++)
    {
        char ch = expression[i];
        //if opening bracket ,stack push
        //if closing bracket ,stack top check & pop

        if(ch == '('||ch == '{'||ch == '[')
        {
            s.push(ch);
        }
        else{
            //for closing brackets 
             if(!s.empty())
             {
                char top  = s.top();
                if((ch == ')'&& top =='(') ||(ch == '}' && top =='{')||(ch == ']'&&top == '['))
                {
                    s.pop();
                }
                else{
                    return false;
                }
             }
             else{
                return false;
             }
        }
    }
     if(s.empty())
        {
            return true ;
        }
        else{
            return false;
        }
}
int main()
{
    string a = "{{{}}}}";
    if(isValidPalindrome(a))
    {
        cout<<"It is valid"<<endl;
    }
    else{
        cout<<"It is invalid"<<endl;
    }
   
}