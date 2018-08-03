#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100];
int temp[100];
int main()
{
    int n,r;
    int p,c;
    while(cin>>n>>r&&(n+r))
    {
       for(int i=1;i<=n;i++)
       {
           a[i]=n-i+1;
       }
       while(r--)
       {
          cin>>p>>c;
          for(int i=p,j=1;j<=c;j++,i++)
          {
             temp[j]=a[i];
          }
          for(int i=p+c-1,k=1;k<=p-1;k++,i--)
          {
             a[i]=a[i-c];
          }
          for(int i=1;i<=c;i++)
          {
             a[i]=temp[i];
          }
          //for(int i=1;i<=n;i++)
           // cout<<a[i]<<endl;
       }
       cout<<a[1]<<endl;
    }
}     
                                                       
    
