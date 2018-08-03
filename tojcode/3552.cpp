#include<iostream>
using namespace std;
int main()
{
  int  count=1;
  int t;
   cin>>t;
   int n;
   while(t--)
   {
     cin>>n;
     cout<<"Case "<<count++<<": ";
     if(n==1)
       cout<<1<<endl;
     else if(n==2)
       cout<<2<<endl;
     else
       cout<<2*n-4<<endl;
   }
 }      
           