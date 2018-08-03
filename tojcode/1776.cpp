#include<iostream>
#include<cstring>
#include<cmath>
#define eps 1e-6
using namespace std;
double pi=acos(-1.0);
double r=40000/(2*pi);
int k,m;
struct point
{
       double x,y,z;
}s[120],t[120];
bool vis[120];
int main()
{
    while(cin>>k>>m&&(k+m))
    {
        int ans=0;double reach,dis;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<k;i++)
          cin>>s[i].x>>s[i].y>>s[i].z;
        for(int i=0;i<m;i++)
          cin>>t[i].x>>t[i].y>>t[i].z;
        for(int i=0;i<k;i++)
        {
            reach=s[i].x*s[i].x+s[i].y*s[i].y+s[i].z*s[i].z-r*r;
            for(int j=0;j<m;j++)
            {
               if(vis[j])
                 continue;
               else
               {
                 dis=(s[i].x-t[j].x)*(s[i].x-t[j].x)+(s[i].y-t[j].y)*(s[i].y-t[j].y)+(s[i].z-t[j].z)*(s[i].z-t[j].z);
                 if(reach-dis>=eps)
                 {  ans++; vis[j]=1;};
               }
            }
        }
        cout<<ans<<endl;
    }
}     
                                            
                    
    
