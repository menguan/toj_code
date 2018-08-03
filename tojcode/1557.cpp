#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int a[16],b[16],c[16];
int x,y,z;
int main()
{
  for(int i=0;i<16;i++)
  {
    cin>>a[i]>>b[i]>>c[i];
  }
  while(cin>>x>>y>>z)
  {
    if(x==-1&&y==-1&&z==-1)
      return 0;
    int re;
    double min=100000;
    for(int i=0;i<16;i++)    
    {
      double t=sqrt(1.0*(a[i]-x)*(a[i]-x)+(b[i]-y)*(b[i]-y)+(c[i]-z)*(c[i]-z));
      if(t<min)
      {
        min=t;
        re=i;
      }
    }
    printf("(%d,%d,%d) maps to (%d,%d,%d)\n",x,y,z,a[re],b[re],c[re]);
  }
}   