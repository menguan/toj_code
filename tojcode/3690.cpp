#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> v[210];
int sg(int u,int fa)
{
    int ret=0;
    for(int i=0;i<v[u].size();i++)
    {
        if(v[u][i]!=fa)
        {
            ret^=(sg(v[u][i],u)+1);
        }
    }
    return ret;
}             
int main()
{
    int t;
    
    while(cin>>t)
    {
      int ans=0;
      int cnt=0;
      while(t--)
      {
          int n;int u,vv;
          cin>>n;
          for(int i=1;i<=n;i++)
            v[i].clear();
          for(int i=0;i<n-1;i++)
          {
            cin>>u>>vv;
            v[u].push_back(vv);
            v[vv].push_back(u);
          }
          int  temp=sg(1,-1);
          if(temp>1)
            cnt++;
          ans^=temp;  
      }             
      if((cnt==0&&ans==0)||(cnt>0&&ans!=0))
        cout<<"PP"<<endl;
      else
        cout<<"QQ"<<endl;
    }
}        
                    
          
             
