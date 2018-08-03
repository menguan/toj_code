#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int a[3000001];
int b[2000000];
void init()
{
     memset(a,0,sizeof(a));
     for(int i=0;i<=1000;i++)
     {
        for(int j=i;j<=1000;j++)
        {
          for(int k=j;k<=1000;k++)
          {
              if(i==j&&j==k)
                a[i*i+j*j+k*k]++;
              else if(i==j||j==k)
              {
                a[i*i+j*j+k*k]+=3;
              }
              else a[i*i+j*j+k*k]+=6;       
          }
        }
     }     
}              
int main()
{
    init();
    int t;int n;
    cin>>t;
    while(t--)
    {
       cin>>n;
       cout<<a[n]<<endl;
   }
}          
