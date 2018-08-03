#include<iostream>
using namespace std;
bool f(int a,int l)
{
  while(a)
  {
    if(l==a%10)
      return 0;
    a/=10;
  }
  return 1;
}      
   
int main()
{
   int n,l,i;
   cin>>n>>l;
   for(i=1;n;i++)
   {
     if(f(i,l))
       n--;
   }
   cout<<i-1<<endl;
  
}       
   