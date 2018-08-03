#include<iostream>
using namespace std;
long long num[10]={0,0,0,0,0,0,0,0,0,0};
inline void f(long long a)
{
  while(a)
  {
    num[a%10]++;
    a/=10;
  }
}    
 
int main()
{
  long long m,n;
  cin>>m>>n;
  for(int i=m;i<=n;i++)
    f(i);
    
  for(int i=0;i<9;i++)
    cout<<num[i]<<" ";
  cout<<num[9]<<endl;
  //while(1);
}        
  
   