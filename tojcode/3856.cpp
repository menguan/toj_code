#include<iostream>
using namespace std;
int f(int n,int m)
{
    long long i,r;
    long long t=m+n;        
    if (n>m) n=m;        
    for (r=1,i=t-n+1;i<=t;i++) 
    r=(r*i)/(i-t+n); 
    return r; 
}        
int main()
{    
  long long n,m,i,b,c;    
  while (cin>>n>>m>>b>>c)    
  {        
    long long nn=n-b;
    long long mm=m-c;
    if (m==0&&n==0) break;        
       
    cout<<f(m,n)-f(b,c)*f(nn,mm)<<endl;;    
  }    
    return 0;
}   