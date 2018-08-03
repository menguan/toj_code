#include<iostream>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int g[50][50];
int belong[100];
map<int,int> con;
map<int,int>::iterator it;
vector<int> city[101];
int main()
{
    int n,m;int temp;
    int u,v;
    while(cin>>n>>m)
    {
      con.clear();
      for(int i=0;i<100;i++)
        city[i].clear();
      int cnt=0;
      for(int i=1;i<=n;i++)
      {
          cin>>temp;
          it=con.find(temp);
          if(it==con.end())
          {
           con[temp]=cnt++;
           //cout<<"kk"<<endl;
          }
          belong [i] =con[temp];
          city[con[temp]].push_back(i);
      }
     memset(g,0,sizeof(g));
     for(int i=0;i<m;i++)
     {
         
         cin>>u>>v;
         if(belong[u]==belong[v])
         {
            g[u][v]=g[v][u]=1;
         }
     }
     for(int i=1;i<=n;i++)
       g[i][i]=1;
      // cout<<g[1][1]<<endl;
     for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
     for(int k=1;k<=n;k++)
     {
       if(g[j][i]&&g[i][k])
         g[j][k]=1;
       //g[j][k]=g[j][i]&g[i][k];
       //if(g[j][k])
       //{
       //    cout<<j<<" "<<i<<" "<<k<<endl;       
       //}
     }
     int ans=0;
     
     for(it=con.begin();it!=con.end();it++)
     {
          
          int te=it->second;
          //cout<<te<<endl;
          bool flag=1;
          for(int i=0;i<city[te].size();i++)
          {
              for(int j=0;j<city[te].size();j++)
              {
                   //cout<<te<<" "<<city[te][i]<<" "<<city[te][j]<<" "<<g[city[te][i]][city[te][j]]<<endl;
                   if(!g[city[te][i]][city[te][j]])
                   {  
                   flag=0;break;}
              }
              if(!flag)
                break;
          }
          if(!flag)
            ans++;
     }
     cout<<ans<<endl;
     }
}      
                   
                                                          
                              
                                              
