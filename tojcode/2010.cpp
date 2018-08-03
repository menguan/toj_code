#include<iostream>
using namespace std;
int prime[5000];

int c=7;
void p()
{
  bool k;
  for(int i=15;i<10000;i+=2)
  {
    k=1;
    for(int j=3;j*j<=i;j++)
    {
      if(i%j==0)
      {
       k=0;
       break;
      }
    }
    if(k)
    {
      prime[c++]=i;
    }
  }
}    
        
      
    

int main()
{
  prime[1]=2;
  prime[2]=3;
  prime[3]=5;
  prime[4]=7;
  prime[5]=11;
  prime[6]=13;
  p();
  int n;
  while(cin>>n,n)
  {
    int re=0;
    for(int i=1;i<c;i++)
    {
      int sum=0;
      if(prime[i]>n)
      break;
      
      for(int j=i;;j++)
      {
        sum+=prime[j];
        if(sum>n)
        break;
        
        if(sum==n)
        re++;
      }
    }
    cout<<re<<endl;
  }
}