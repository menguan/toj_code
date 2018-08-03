#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<stdio.h>
using namespace std;
typedef struct Node
{   
     queue<int>q;   
     }Node;
Node num[1001];
queue<int>qn;
map<int,int>m;
bool s[1001];
char b[100];   
int main()
{
    int i,j,k,t,x,y,len,c=1,temp;
    while(scanf("%d",&t)!=EOF)
    {
          if(t==0)break;
          m.clear();
          while(!qn.empty())qn.pop();
          for(i=1;i<=t;i++)
          {
              while(!(num[i].q).empty())(num[i].q).pop();
              s[i]=0;             
              }
          for(i=1;i<=t;i++)
          {
              scanf("%d",&k);
              for(j=1;j<=k;j++)
              {
                  scanf("%d",&x); 
                  m[x]=i;           
                  }             
              }
          printf("Scenario #%d\n",c++);                
          while(scanf("%s",b)!=EOF)
          {
                if(b[0]=='S')break;
                if(b[0]=='E')
                {
                   scanf("%d",&x);
                   k=m[x];
                   if(s[k]==0)
                   {
                      s[k]=1;        
                      qn.push(k);
                      (num[k].q).push(x);           
                      }
                   else
                   {
                      (num[k].q).push(x);      
                      }             
                   }
                else if(b[0]=='D')
                {
                   k=qn.front();
                   temp=(num[k].q).front();
                   printf("%d\n",temp);
                   (num[k].q).pop();
                   if(num[k].q.empty())
                   {
                      qn.pop();
                      s[k]=0;                 
                      } 
                   }                      
                }
          printf("\n");                  
          }
    return 0;
    } 