#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
bool con[30][30];int st,en;
int main()
{
    int t;int n,m;
    cin>>t;
    while(t--)
    {
       memset(con,0,sizeof(con));
       cin>>n>>m;
       for(int i=0;i<m;i++)
       {
         cin>>st>>en;
         con[st][en]=1;
       }
       for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
       for(int k=1;k<=n;k++)
       {
          if(con[j][i]&&con[i][k])
            con[j][k]=1;
       }
       bool flag=0;
       for(int i=1;i<=n;i++)
         if(con[i][i])
           flag=1;
       if(flag)
         cout<<0<<endl;
       else
         cout<<1<<endl;
    }
}      
                                 
                      
