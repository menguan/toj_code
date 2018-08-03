#include<iostream>
#include<cmath>
const int Max=32769;
 
using namespace std;
bool re[Max];

inline bool isprime(int n)
{
  int m=(int)sqrt(n*1.0);
  for(int i=3;i<=m;i+=2)
  {
    if(n%i==0)
    return 0;
  }
  return 1;
}
void f()
{  
   re[2]=1;
   for(int i=3;i<Max;i+=2)
   {
     if(isprime(i))
     re[i]=1;
   }  
}   
int main()
{
  f();
  int n;
  while(cin>>n,n)
  {
    int count=0;
    
    
    for(int i=2;i<=n/2;i++)
    {
      
      if(re[i]&&re[n-i])
      count++;
    }
    cout<<count<<endl;
  }
}    