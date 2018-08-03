#include<iostream>
#include<cstring>
#include<stdio.h> 
#include<algorithm>
using namespace std;
bool flag[100010];
int c[100010];
int n[15];
int d[15];
int maxn,money,N;
int main()
{
  
  while(cin>>money)
  {
    cin>>N;
    for(int i=0;i<N;i++)
    {
      cin>>n[i]>>d[i];
    }
    memset(flag,0,sizeof(flag));
    flag[0]=1;
    maxn=0;
    for(int i=0;i<N;i++)
    {
      memset(c,0,sizeof(c));
      for(int j=d[i];j<=money;j++)
      {
        if(flag[j]==0&&flag[j-d[i]]==1&&c[j-d[i]]<n[i])
        {
          flag[j]=1;
          c[j]=c[j-d[i]]+1;
          if(j>maxn)
            maxn=j;
        }
      }
    }
    cout<<maxn<<endl;
  }
}              