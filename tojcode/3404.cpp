#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int id[100010];int sz[100010];
int deg[100010];
int odd[100010];int used[100010];
int init()
{
    for(int i=0;i<100010;i++)
    {  id[i]=i;
        sz[i]=1;
        deg[i]=0;
        odd[i]=0;
        used[i]=0;
    }
}        
        
int find(int p)
{
    while(p!=id[p])
    {
         id[p]=id[id[p]];
         p=id[p];
    }
    return p;
}
void unio(int m,int n)
{
     int p=find(m);
     int q=find(n);
     if(p==q)
       return ;
     if(sz[p]>sz[q])
     {
                    sz[p]+=sz[q];
                    id[q]=p;
     }
     else
     {
         sz[q]+=sz[p];
         id[p]=q;
         }  
}
int main()
{
    int n,m;int st,en;
    while(cin>>n>>m)
    {
        init();
        while(m--)
        {
            cin>>st>>en;
            deg[st]++;deg[en]++;
            unio(st,en);
        }
        int ans=0;
        vector<int> q;
        int temp;
        for(int i=1;i<=n;i++)
        {
           temp=find(i);
           if(used[temp]==0)
           {
             q.push_back(temp);
             used[temp]=1;
             }  
             
           if(deg[i]%2==1) odd[temp]++;
        }
        for(int i=0;i<q.size();i++)
        {
            
              temp=q[i];
            if(deg[temp]==0)
              continue;
            if(odd[temp]==0)
              ans++;
            else
              ans+=odd[temp]/2;
        }
        cout<<ans<<endl;
    }
}             
               
             
            
                              
                               
                             
                   
