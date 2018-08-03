//***************************
//****************************
//*************************
#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX 1000000
char c[205];
int len;
string a[205][205];
int minlen[205][205];
void dp()
{
 int i,j,k;
 for(i=0;i<len;i++)
  for(j=i;j<len;j++)
  {
   a[i][j]="";
   minlen[i][j]=MAX;
  }

  for(i=0;i<len;i++)
    for(j=0;j<i;j++)
  {
      a[i][j]="";
      minlen[i][j]=0;
  }
 for(i=len-1;i>=0;i--)
  for(j=i;j<len;j++)
  {
   if(i==j)
   {
    if(c[i]=='('||c[i]==')')
     a[i][j]="()";
    else a[i][j]="[]";
    minlen[i][j]=1;
   }
   else
   {
    if(c[i]=='('&&c[j]==')')
    {
     if(minlen[i+1][j-1]<minlen[i][j])
     {
      a[i][j]="("+a[i+1][j-1]+")";
      minlen[i][j]=minlen[i+1][j-1];
     }
    }
    if(c[i]=='['&&c[j]==']')
    {
     if(minlen[i+1][j-1]<minlen[i][j])
     {
      a[i][j]="["+a[i+1][j-1]+"]";
      minlen[i][j]=minlen[i+1][j-1];
     }
    }
    for(k=i;k<j;k++)
     if(minlen[i][k]+minlen[k+1][j]<minlen[i][j])
     {
      minlen[i][j]=minlen[i][k]+minlen[k+1][j];
      a[i][j]=a[i][k]+a[k+1][j];
     }
   }
  }
}
int main()
{
    while(gets(c))
   {
    len=strlen(c);
    if(len==0)  {cout<<endl;continue;}
    dp();
    cout<<a[0][len-1]<<endl;
   }
}
