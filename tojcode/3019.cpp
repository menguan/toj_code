#include<iostream>
using namespace std;
long long a[51];
int main()
{
  int n;
  while(cin>>n,n)
  {
    for(int i=0;i<51;i++)
      a[i]=0;
    for(int i=1;i<=n;i++)
      cin>>a[i]; 
    long long sum=0;   
    for(int i=n;i>0;i--)
    {
      sum+=a[i];
      //cout<<a[i]<<" "<<sum<<endl;
      for(int j=i-1;j>0;j--)
      {
        a[j]+=a[i];
        //cout<<a[j]<<endl;
      }  
    }
    cout<<sum<<endl;
  }
}  