#include<iostream>
#include<algorithm>
using namespace std;
bool flaga,flagb;
void f(int a,int b,int pos)
{
  if(flaga)
    return;
  if(a==1&&b==1)
  {
    flaga=flagb=1;
    return ;
  }
  if(b==1)
  {
    flagb=1;
  }
  for(int i=pos;i>1;i--)
  {
    if(a%i==0)
      f(a/i,b,i-1);
    if(b%i==0)
      f(a,b/i,i-1);
     
  }
  return ; 
}       
            
int main()
{
  int a,b;
  while(cin>>a>>b)
  {
    flaga=flagb=0;
    if(a<b)
      swap(a,b);
    f(a,b,100);
    if(!flaga&&flagb)
      cout<<b<<endl;
    else
      cout<<a<<endl;
  }
}        
      