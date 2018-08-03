#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct f
{
       
       double l,r;
}a[10010]; bool vis[10010];
bool cmp(f mm,f nn)
{
     if(mm.r!=nn.r)
       return mm.r<nn.r;
     else
       return mm.l<nn.l;
}             
int main()
{
    int n,d;
    int x,y;bool flag=1;int con=1;
    while(cin>>n>>d&&(n+d))
    {
        flag=1;
        for(int i=0;i<n;i++)
        {
                cin>>x>>y;
                if(abs(y)>d)
                  flag=0;
                double len= sqrt(d*d*1.0-y*y) ;
                a[i].l=x-len;
                a[i].r=x+len;
        }
        cout<<"Case "<<con++<<": ";
        if(flag==0)
        {
          cout<<"-1"<<endl;
        }
        else
        {
            sort(a,a+n,cmp);
            memset(vis,0,sizeof(vis));
            int ans=0;
            for(int i=0;i<n;i++)
            {
                if(vis[i]==1)
                  continue;
                else
                {
                    vis[i]=1;
                    ans++;
                    for(int j=i+1;j<n;j++)
                    {
                            if(a[j].l<=a[i].r)
                              vis[j]=1;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
}                   
                       
                                 
        
    
    
