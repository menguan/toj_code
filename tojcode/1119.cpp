/*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa  aaa  aaaaa                 aaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaa  aaaaaa 
aaaaa    aaaaa    aaaaaaaaaaaaaaaaaaaa   aaaaaaaa
aaaaa aaaaa          aaaaaaaaaaaaaaa   aaaaaaaaaa
aaaaa aaaaaaaa   aaaaaaaaaaaaaaaaa   aaaaaaaaaaaa
aaaaa    aaaaa     aaaaaaaaaaaa    aaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaa   aaaaaaaaaaaaaaaaa
aaaaaa a aaaaa   aa  aaaaaa   aaaaaaaaaaaaaaaaaaa
aaaaaaa  aaaaa  aaaaa aaaaa                aaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
#include<iostream>
#include<string.h>
#include<cmath>
#include<stdio.h>
#include<vector>
using namespace std;
int match[200];
bool vis[200];
vector<vector<int> > adj;
int n,m,k;int st,en;int pos;
bool find(int p)
{
     for(int i=0;i<adj[p].size();i++)
     {
        int temp=adj[p][i];
        if(!vis[temp])
        {
           vis[temp]=1;
           if(match[temp]==-1||find(match[temp]))
           {
               match[temp]=p;
               return 1;
           }
        }
     }
     return 0;
}
                                                               
void erfen()
{
     int ret=0;
     for(int i=0;i<n;i++)
     {
         memset(vis,0,sizeof(vis));
         if(find(i))
           ret++;
     }
     cout<<ret<<endl;
}
int main()
{
    while(cin>>n,n)
    {
       cin>>m>>k;
       memset(match,-1,sizeof(match));
       adj.assign(n+1,vector<int>());  
       for(int i=0;i<k;i++)
       { 
          cin>>pos>>st>>en;
          if(st&&en)
          adj[st].push_back(en);
       }
       erfen();
    }
}                 
