#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
int id[500000];
int sz[500000];
set<string> t;
map<string,int> num;
struct Edge
{
   int u,v;double dis;
}edge[500000];
void init()
{
     for(int i=0;i<500000;i++)
     {id[i]=i;sz[i]=1;}
}
bool cmp(Edge m,Edge n)
{
     return m.dis<n.dis;
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
void uni(int p,int q)
{
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
    double slen;
    double  len;
    double ans;
    int n,m;int con;
    string s;        string s1,s2;
    t.clear();
    num.clear(); 
    init();
    ans=0;                  
    cin>>slen;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        num[s]=i;
        //cout<<num[s]<<endl;
    }    
    cin>>m;
    for(int i=0;i<m;i++)
    {
       cin>>s1>>s2>>edge[i].dis;
       edge[i].u=num[s1];
       edge[i].v=num[s2];
    //   cout<<num[s1]<<endl;
    }
    sort(edge,edge+m,cmp); 
    int p,q;con=0;
    for(int i=0;i<m;i++)
    {
       if(con==n-1)
         break;
       //cout<<edge[i].u<<" "<<edge[i].v<<endl;  
       p=find(edge[i].u);
       q=find(edge[i].v);
       //cout<<p<<" "<<q<<endl;
       if(p==q)
         continue;         
       uni(p,q);
       con++;
       ans+=edge[i].dis;
    }
    //ans=((int)(ans*10+0.5))/10.0;//cout<<ans<<endl;
    if(ans>slen)
     cout<<"Not enough cable"<<endl;
    else
      cout<<"Need "<<setprecision(1)<<fixed<<ans<<" miles of cable"<<endl;   
    //while(1);
}   
