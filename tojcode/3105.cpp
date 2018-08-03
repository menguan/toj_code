#include<iostream>
#include<algorithm>
using namespace std;
int prime[50000];
void f()
{
  prime[1]=2;
  prime[2]=3;
  prime[3]=5;
  prime[4]=7;
  for(int i=11,k=5;i<=100000;)
  {
     int t=i;
     for(int j=3;j*j<=i;j++)
     {
       if(i%j==0)
       {
        i+=2;
        break;
       } 
     }
     if(t==i)
     {
       prime[k]=i;
       k++;
       i+=2;
     }
  }
}       
     
         
      
    
    

int main()
{
  f();
  int n,m;
  cin>>n;
  while(n--)
  {
    cin>>m;
    cout<<prime[m]<<endl;
  }
}    

