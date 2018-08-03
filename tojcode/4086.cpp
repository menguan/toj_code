#include<iostream>
#include<cmath>
using namespace std;
int f(int a,int b)
{
    if(a>b)
    {
           int temp=a;
           a=b;
           b=temp;
   }
   int r=b%a;
   while(r)
   {b=a;
        a=r;
        
        r=b%a;
}
return a;
}              
           
int main()
{
    int t;int m,n;int count=1;
    while(cin>>m>>n)
    {
       cout<<"Scenario #"<<count++<<":"<<endl;

       if(n%m==0)
         cout<<0<<endl;
       else 
       {
            cout<<m-f(n,m)<<endl;
         
          }             
}}    
