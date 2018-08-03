#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
int hash[10101010];
int n,m,k,t;
int main()
{
    while(cin>>n>>m)
    {
       memset(hash,0,sizeof(hash));
       int ans=0;
       while(n--)
       {
          int temp=0;
          cin>>k;
          while(k--)
          {
              cin>>t;
              temp|=(1<<(t-1));
          }
          hash[temp]=1;
          for(int j=0;j<=16384;j++)
          {
             if(hash[j])
             {
               hash[temp|j]=1;
             }
          }
       }
       for(int i=0;i<=16384;i++)
         if(hash[i]) ans++;
       cout<<ans<<endl;
    }
}                                           
