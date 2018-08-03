#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
bool judge(int *a,int n)
{
     stack<int> s;
     int k=0;
     for(int i=1;i<=n;i++)
     {
          s.push(i);
          if(i==a[k])
          {
             while(!s.empty()&&s.top()==a[k])
             {
                k++;
                s.pop();
             }
          }
     }
     if(s.empty())
       return 1;
     return 0;
}                                           

int main()
{
    int t;int n;
    int a[20];
    cin>>t;
    while(t--)
    {
         cin>>n;
         for(int i=0;i<n;i++)
           a[i]=i+1;
         if(judge(a,n))
         {
            for(int i=0;i<n;i++)
               cout<<a[i];
            cout<<endl;
         }
         while(next_permutation(a,a+n))
         {
             if(judge(a,n))
             {
                 for(int i=0;i<n;i++)
                   cout<<a[i];
                 cout<<endl;
             }
         }
    }
}                                                   
                
     
