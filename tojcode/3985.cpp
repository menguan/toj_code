#include<iostream>
#include<iomanip>
using namespace std;      
int main()
{
  int n,a,b,c;
  cin>>n;
  while(n--)
  {
     cin>>a>>b>>c;
     long double t=1;
     for(int i=c,j=a,k=b;i>0;j--,i--,k--)
       t=t/j*k;
       
      
     if(b==0)
     t=0;
     cout<<setprecision(4)<<fixed<<t<<endl;
  }
} 