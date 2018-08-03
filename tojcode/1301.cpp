#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;
double a[1010];
int main()
{
  int n;
  while(cin>>n,n)
  {
    double sum=0,ave;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      sum+=a[i];
    }
    
    ave=floor(sum/n*100+0.5)/100.0;//还要加个0.5 
    
    double sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
      if(ave-a[i]>0.00000005)
        sum1+=ave-a[i];
      else
        sum2+=a[i]-ave; 
    }
    cout<<"$"<<setprecision(2)<<fixed<<min(sum1,sum2)<<endl;
  }
}     