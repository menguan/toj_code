#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
bool con[60][60];
int num[10000];
int main()
{
    int n,m;
    while(scanf("%d",&n)!=EOF)
    {
       memset(con,0,sizeof(con));
       scanf("%d",&m);
       bool flag=1;
       if(m!=n*(n-1)/2)
         flag=0;
       for(int i=0;i<m;i++)
       {
          scanf("%d",&num[i]);
       }
       if(flag)
       {
          for(int i=1;i<m;i++)
          {
              con[num[i-1]][num[i]]=con[num[i]][num[i-1]]=1;
          }
          con[num[0]][num[m-1]]=con[num[m-1]][num[0]]=1;
          for(int i=0;i<n;i++)
          {
              if(flag)
              for(int j=0;j<n;j++)
              {
                  if(i==j)
                    continue;
                  if(con[i][j]==0)
                  {
                   flag=0;
                   break;
                  }
              }
          }
       }
          if(flag)
            puts("Accepted");
          else 
            puts("Wrong Answer");
       }
}                   
                  
                            
                                               
