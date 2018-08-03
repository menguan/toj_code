#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int in[200];
bool con[200][200];
bool vis[200];
vector<int> v;
int main()
{
   int t; int n,m;int st,en;
   cin>>t;
   while(t--)
   {
     memset(in,0,sizeof(in));
     memset(con,0,sizeof(con));
     memset(vis,0,sizeof(vis));
     v.clear();
     cin>>n>>m;
     while(m--)
     {
         cin>>st>>en;
         if(con[st][en]==0)
         {
         con[st][en]=1;
         in[en]++;
         }
     }
     bool flag=0;
     while(1)
     {
        if(v.size()==n)
          break;
        flag=0;  
        for(int i=1;i<=n;i++)
        {
           if(in[i]==0&&!vis[i])
           {
             v.push_back(i);
             vis[i]=1;
             flag=1;
             for(int j=1;j<=n;j++)
             {
                if(con[i][j])
                {
                  in[j]--;
                }
             }
             break;
           }
        }
        if(flag==0)
          break;
     }
     if(flag==0)
       cout<<"Low IQ"<<endl;
     else
     {
        for(int i=0;i<n;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
     }
   }
}               
      
                             
                             
                                                                      
                        
