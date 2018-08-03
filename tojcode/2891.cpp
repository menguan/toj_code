#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
      int n;
      cin>>n;
      int num[n];
      for(int i=0;i<n;i++)
      {
        cin>>num[i];
      }
      while(n)
      {
         n--;
         for(int i=0;i<n;i++)
         {
           num[i]=num[i+1]-num[i];
         }
      }
      cout<<num[0]<<endl;      
   }
} 