#include<iostream>
#include<stack>
#include<vector>
using namespace std;


class Solution{
    private:
    bool knows(vector<vector<int> >& M, int a , int b, int n)
    {
        if(M[a][b]==1)
        {
            return true;
        }
        else{
            return false;
        }
    }

    public:
    //function to find out whether there is a celebrity in the party or not
    int celebrity(vector<vector<int> >& M,int n)
    {
        stack<int>s;
        //step1 : push all element in stack
        for(int i = 0 ; i<n;i++)
        {
            s.push(i);
        }
        //step2: get two elements and compare them 

        while(s.size()>1)
        {
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if(knows(M,a,b,n))
            {
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int ans = s.top();
        //step 3: single element in stack is potential celebrity 
        //so verify it 
        
        int zeroCount = 0;

        for(int i = 0 ; i<n ; i++)
        {
            if(M[ans][i]==0)
                zeroCount++;   
        }

    //all zeros
    if(zeroCount != n)
       return -1;
    

    //column check
    int oneCount = 0;

    for(int i = 0;i<n;i++)
    {
        if(M[i][ans] == 1)
            oneCount++;
    }

    if(oneCount != n-1)
        return -1;

    return ans;
    }
};
// class Solution{
//     private:
//     bool knows(vector<vector<int> >& M, int a , int b, int n)
//     {
//         if(M[a][b]==1)
//         {
//             return true;
//         }
//         else{
//             return false;
//         }
//     }

//     public:
//     //function to find out whether there is a celebrity in the party or not
//     int celebrity(vector<vector<int> >& M,int n)
//     {
//         stack<int>s;
//         //step1 : push all element in stack
//         for(int i = 0 ; i<n;i++)
//         {
//             s.push(i);
//         }
//         //step2: get two elements and compare them 

//         while(s.size()>1)
//         {
//             int a = s.top();
//             s.pop();

//             int b = s.top();
//             s.pop();

//             if(knows(M,a,b,n))
//             {
//                 s.push(b);
//             }
//             else{
//                 s.push(a);
//             }
//         }
//         int candidate = s.top();
//         //step 3: single element in stack is potential celebrity 
//         //so verify it 
//         bool rowCheck = false;
//         int zeroCount = 0;

//         for(int i = 0 ; i<n ; i++)
//         {
//             if(M[candidate][i]==0)
//                 zeroCount++;   
//         }

//     //all zeros
//     if(zeroCount == n)
//     {
//         rowCheck = true;
//     }

//     //column check
//     bool colCheck = false;
//     int oneCount = 0;

//     for(int i = 0;i<n;i++)
//     {
//         if(M[i][candidate] == 1)
//             oneCount++;
//     }

//     if(oneCount== n-1)
//     {
//         colCheck = true;
//     }

//     if(rowCheck == true && colCheck == true )
//         return candidate;
//     else
//         return -1;
//     }

// };
int main()
{
    vector<vector<int>>M = {{0,1,0},{0,0,0},{0,1,0}};
  //vector<vector<int>>M = {{0,1},{1,0}};  // answer is -1
    int n = 2;
    Solution s;
    
    int ans = s.celebrity(M,n);
    

    cout<<"The answer is "<<ans<<endl;
        



}