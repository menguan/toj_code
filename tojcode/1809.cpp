#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double a[30];
int main()
{
  int n;
  while(cin>>n,n)
  {
      double sum=0;
      for(int i=0;i<n;i++)
      {
        cin>>a[i];
      }     
      sort(a,a+n);
      bool flag=0;
      for(int i=0;i<n-1;i++)
      {
        sum+=a[i];
        //cout<<sum<< " "<<a[i+1]<<endl;
        if(sum>=a[i+1])
        {
          flag=1;
          break;
        }  
      }
      if(flag)
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
   }
}   