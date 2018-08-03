#include<iostream>
#include<cmath>
using namespace std;
int main()
{
      int m,n,k;
      while(cin>>n>>m>>k)
      {
          if(m==0&&n==0&&k==0) 
            return 0;
          if(m<8&&n<8)
          {
            cout<<0<<endl;
            continue;
          }
          m-=7;
          n-=7;     
          if(m*n%2==0||k==0)
            cout<<m*n/2<<endl;
          else
            cout<<m*n/2+1<<endl;  
          
          
      }
      return 0;
}