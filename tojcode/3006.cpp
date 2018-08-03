#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int a[50][50];
int word[10];
char s[1000];
void f(int n)
{
  
  for(int i=0;i<5;i++)
    word[i]=0;
  if(n==32)
    return;  
  int t=n-64;
  int d=4;
  while(n)
  {
    word[d--]=n%2;
    n/=2;
  }  
}    
 
int main()
{
  int t,r,c,count=1;
  cin>>t;
  while(t--)
  {
    for(int i=0;i<50;i++)
    for(int j=0;j<50;j++)
      a[i][j]=-1;
    cin>>r>>c;   
    getchar();
    gets(s);
    cout<<count++<<" ";
    int nowr=1,nowc=1;
    int p=2;
    for(int i=0;i<strlen(s);i++)
    {
      f((int)s[i]);
      for(int j=0;j<5;j++)
      {
        if(p==2)
        {
          if(nowc+1>c||a[nowr][nowc+1]!=-1)
          {
            a[nowr++][nowc]=word[j];
            p=3;
            continue;
          }
          else
          {
            a[nowr][nowc++]=word[j];
            continue;
          }
        }
        if(p==3)
        {
          if(nowr+1>r||a[nowr+1][nowc]!=-1)
          {
            a[nowr][nowc--]=word[j];
            p=4;
            continue;
          }
          else
          {
            a[nowr++][nowc]=word[j];
            continue;
          }
        }
        if(p==4)
        {
          if(nowc-1<1||a[nowr][nowc-1]!=-1)
          {
            a[nowr--][nowc]=word[j];
            p=1;
            continue;
          }
          else
          {
            a[nowr][nowc--]=word[j];
            continue;
          }
        }
        if(p==1)
        {
          if(nowr-1<1||a[nowr-1][nowc]!=-1)
          {
            a[nowr][nowc++]=word[j];
            p=2;
            continue;
          }
          else
          {
            a[nowr--][nowc]=word[j];
            continue;
          }
        }
       }
     }
     for(int i=1;i<=r;i++)
     {
       for(int j=1;j<=c;j++)
       {
         if(a[i][j]==-1)
           cout<<0;
         else
           cout<<a[i][j];
       }
     }
     cout<<endl;
   }
}   
   