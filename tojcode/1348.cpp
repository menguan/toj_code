#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
int n;
int id[120];
void init()
{
     for(int i=0;i<=n;i++)
     {
        id[i]=i;
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
void unio(int p,int q)
{
     id[p]=q;
}                    
struct point
{
     double x,y;
     int pos;
}po[120];
struct linee
{
   double len;
   int u,v;
}line[10010];
bool cmp(linee mm,linee nn)
{ 
     return mm.len<nn.len;
}        
       
int main()
{
    int t;int bnum=0;double ans=0;
    int pp,qq;
    
    cin>>n;init();
    for(int i=1;i<=n;i++)
    {
       cin>>po[i].x>>po[i].y;
       po[i].pos=i;
    }
    for(int i=1;i<n;i++)
    {
       for(int j=i+1;j<=n;j++)
       {
           line[bnum].len=hypot(po[i].x-po[j].x,po[i].y-po[j].y);
           line[bnum].u=i;
           line[bnum].v=j;
           bnum++;
       }
    }
    sort(line,line+bnum,cmp);
    //for(int i=0;i<bnum;i++)  cout<<line[i].len<<endl;
    int count=1;
    for(int i=0;i<bnum;i++)
    {
       pp=find(line[i].u);
       qq=find(line[i].v);
       
       if(pp!=qq)
       {
          //cout<<"kk"<<endl;
          ans+=line[i].len;
          unio(pp,qq);
           count++;
       }
       if(count==n)
         break;
    }
    cout<<setprecision(2)<<fixed<<ans<<endl;
    //while(1);
}                    
            
        
                            
