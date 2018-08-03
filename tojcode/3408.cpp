#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int dp[11][10010];
struct sneak
{
     int c,w;
};
vector<sneak> s[11];
int main()
{
    int N,V,K,i,j,k;
    while(cin>>N>>V>>K)
    {
       for(i=0;i<=K;i++)
         s[i].clear();
       sneak t;
       for(i=0;i<N;i++)
       {
           cin>>j>>t.c>>t.w;
           s[j].push_back(t);
       }
       bool flag=0;
       for(i=1;i<=K;i++)
       {
           if(s[i].size()==0)
           {
             flag=1;
             break;
           }
       }
       if(flag)
       {
         cout<<"Impossible"<<endl;
         continue;
       }
       for(i=1;i<=K;i++)
         for(j=0;j<=V;j++)
           dp[i][j]=-1;
       for(i=0;i<=V;i++)
         dp[0][i]=0;
       for(i=1;i<=K;i++)
         for(j=0;j<s[i].size();j++)
           for(k=V;k>=s[i][j].c;k--)
             dp[i][k]=max(dp[i][k],max(dp[i][k-s[i][j].c]+s[i][j].w,dp[i-1][k-s[i][j].c]+s[i][j].w));
       if(dp[K][V]<0) 
         cout<<"Impossible"<<endl;
       else 
         cout<<dp[K][V]<<endl;
    }
}
     
                                                                        
