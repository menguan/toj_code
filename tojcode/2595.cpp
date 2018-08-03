#include<iostream>
#include<algorithm>
using namespace std;
long long a[1000010];
int main()
{
  int n;
  bool flag1=0;//get
  bool flag2=0;//not
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }  
  sort(a,a+n);
  if(a[0]+a[1]<=a[n-1])
  {
    flag2=1;
  }
  for(int i=0;i<n-2;i++)
  {
    if(a[i]+a[i+1]>a[i+2])
    {
      flag1=1;
      break;
    }
  }
  if(flag1&&flag2)
    cout<< "The set is accepted."   <<endl;
  else
    cout<< "The set is rejected."   <<endl;
  //while(1);
}            