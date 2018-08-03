#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
short int k1[1000000];
short int k2[1000000];
short int k3[1000000];
char a[1000000];
char b[1000000];
char c[1000000];
int f(int s,int d,int g)
{
  if(s==d&&d==g)
  return s;
  else if(s==d)
  return g;
  else if(g==d)
  return s;
  else if(s==g)
  return d;
}  
  
int main()
{
  gets(a);
  gets(b);
  gets(c);
  int la=strlen(a);a[la]=' ';a[la+1]='\0';la=strlen(a);
  int lb=strlen(b);b[lb]=' ';b[lb+1]='\0';lb=strlen(b);
  int lc=strlen(c);c[lc]=' ';c[lc+1]='\0';lc=strlen(c);
  int low=0;
  int count=0;
  for(int i=0;i<la;i++)
  {
    k1[count]=0;
    if(a[i]==' ')
    {
      for(int j=i-1,k=1;j>=low;j--,k*=10)
      {
        k1[count]+=((a[j]-'0')*k);
      }
      count++;
      low=i+1;
    }
  }
  low=0;
  count=0;
  for(int i=0;i<lc;i++)
  {
    k3[count]=0;
    if(c[i]==' ')
    {
      for(int j=i-1,k=1;j>=low;j--,k*=10)
      {
        k3[count]+=((c[j]-'0')*k);
      }
      count++;
      low=i+1;
    }
  }
  low=0;
  count=0;
  for(int i=0;i<lb;i++)
  {
    k2[count]=0;
    if(b[i]==' ')
    {
      for(int j=i-1,k=1;j>=low;j--,k*=10)
      {
        
        k2[count]+=((b[j]-'0')*k);
      }
      count++;
      low=i+1;
      
    }
  }
  
  for(int i=0;i<count;i++)
  {
    if(i!=count-1)
    cout<<f(k1[i],k2[i],k3[i])<<" ";
    else
    cout<<f(k1[i],k2[i],k3[i])<<endl;
  }
  }  