#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int id[1010];
int n,m;
int find(int p)
{
    while(p!=id[p])
      p=id[p];
    return p;
}  
void init()
{
    for(int i=0;i<=n;i++)
    {
         id[i]=i;
    }
}   
struct f
{
       int a,b;
       int len;
}edge[1010101];
bool cmp(f mm, f nn)
{
   return mm.len<nn.len;
}       
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int cnt=0;
        int ans=-1;
        cin>>n>>m;
        init();
        for(int i=0;i<m;i++)
        {
           cin>>edge[i].a>>edge[i].b>>edge[i].len;
        }
        sort(edge,edge+m,cmp);
        for(int i=0;i<m;i++)
        {
            if(cnt==n-1)  break;
            int pp=find(edge[i].a);
            int qq=find(edge[i].b);
            if(pp==qq)
              continue;
            id[pp]=qq;
            cnt++;
            if(cnt==n-1)
            {
               if(edge[i].len%10)
                 ans=edge[i].len/10+1;
               else
                 ans=edge[i].len/10;
            }
        }
        cout<<ans<<endl;
    }
}
                 
              
                             
