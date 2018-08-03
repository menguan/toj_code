#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
int n;
double tot,ans,money[30];
bool vis[30];
void dfs(int cur,double sum)
{
     if(cur==n)
     {
          if(sum>ans&&sum<tot)
            ans=sum;
          return ;
     }
     if(sum>ans&&sum<tot)
     {
           ans=sum;
     }              
     for(int i=cur;i<n;i++)
     {
          dfs(i+1,sum+money[i]);
          
     }
}            
     
int main()
{
    int T,i,j,t;
    string res[20];
    char kind[4][7]={"spicy","sugar","pepper","duck"};
    cin>>T;
    while(T--)
    {
      ans=0;
      cin>>tot;
      cin>>n;
      memset(money,0,sizeof(money));
      t=n;
      for(j=0;j<n;j++)
      {
         cin>>res[j];
         cin>>money[j];
         for(int i=0;i<4;i++)
         {
              if(res[j].find(kind[i])!=string::npos)
              {
                  money[j]=1010101010;
                  t--;
                  break;
              }
         }
      }
      
      sort(money,money+n);
      n=t;
        dfs(0,0);
      cout<<setprecision(2)<<fixed<<ans<<endl;
    }
}                                                           
