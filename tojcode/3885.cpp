#include <iostream>
#include <cstring>
#include <cmath>
#include<stdio.h>
using namespace std;
int visit[1000000],prime[400000];

void GetPrime()
{
 int cnt=0;
 memset(visit,0,sizeof(visit));
 for(int i=2;i<1000000;i++)
 {
  if(!visit[i])
  {
   prime[cnt++]=i;
  }
  for(int j=0;(j<cnt)&&(i*prime[j]<1000000);j++)
  {
   visit[i*prime[j]]=1;
   if(i%prime[j]==0)
   {
    break;
   }
  }
 }
}

int main(){
 int t,cases=1;
 cin>>t;
 GetPrime();          
 while(t--)
 {
  long long a,b;
  cin>>a>>b;
  int flag=1;
  for(int i=0;prime[i]<=(int)sqrt(a*1.0)&&prime[i];i++)
  {
   int x=prime[i];
   if(a%x==0)
   {
    if(b%x!=0)
    {
     flag=0;
     break;
    }
    while(a%x==0)
    {
     a/=x;
    }
   }
  }
  if(a!=1&&b%a!=0)
  {
    flag=0; 
  }
  printf("Case #%d: ",cases++);
  printf(flag?"YES\n":"NO\n");
 }
}

