#include<iostream>
#include<cstring>
using namespace std;
bool a[1000010];
bool vis[1000010];

int main()
{
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
    for(int i=2;i<1000010;i++)
    {
       if(!vis[i])
       {
         for(int j=i+i;j<1000010;j+=i)
         {
             vis[j]=1;
         }
       }
    }
    vis[0]=vis[1]=1;
    for(int i=0;;i++)
    {
         int temp=(i+1)*(i+1)*(i+1)-i*i*i;
         if(temp>1000000)  break;
         if(!vis[temp])
           a[temp]=1;
    }
    int l;
    while(cin>>l)
    {
      int ans=0;
      for(int i=0;i<=l;i++)
      {
        if(a[i])
        {
          //cout<<i<<endl;
          ans++;
        }
      }
      if(ans)
      cout<<ans<<endl;
      else
      cout<<"No Special Prime!"<<endl;
    }
}                            
            
