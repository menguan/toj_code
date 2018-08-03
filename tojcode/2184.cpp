#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[501],b[501]; 
int main()
{
  int n,k;
  while(cin>>n>>k&&(n+k))
  {
    int len1=0,len2=0;
    int t;
    for(int i=0;i<n;i++)
    {
      cin>>t;
      if(t%2)
      {
        a[len1++]=t;
      }
      else
        b[len2++]=t;
    }
    sort(a,a+len1);
    sort(b,b+len2);
    int t1=0,t2=0;int cnt=0;
    while(t1<len1&&t2<len2)
    {
      if(abs(a[t1]-b[t2])<=k)
      {
        cnt++;
        t1++;
        t2++;
      }  
      else if(a[t1]>b[t2])
      {
        t2++;
      }
      else if(a[t1]<b[t2])
      {
        t1++;
      }
    }
    cout<<cnt<<endl;
  }
}            
      
            
      