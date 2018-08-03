#include<iostream>
#include<cstring>
#include<cmath>
#define sign(x) ((x)>eps?1:((x)<-eps?(-1):(0)))
#define eps 1e-8
using namespace std;
struct point { double x,y;};
inline double xmult(point o,point a,point b) 
{ return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y); }
int inside_convex(point q,point p[],int n) 
{ int i,s[3]= {1,1,1}; 
  for (i=0; i<n&&s[1]|s[2]; i++) 
  s[(sign(xmult(p[(i+1)%n],q,p[i]))+3)%3]=0; 
  return s[1]|s[2]; 
}
point p[10100];
point pol[30];
int main()
{
    int t;int n,m;
    cin>>t;
    while(t--)
    {
       cin>>n;
       for(int i=0;i<n;i++)
         cin>>p[i].x>>p[i].y;
       cin>>m;
       for(int i=0;i<m;i++)
         cin>>pol[i].x>>pol[i].y;
       int ans=0;
       for(int i=0;i<n;i++)
       {
           //cout<<p[i].x<<" "<<p[i].y<<" "<<inside_convex(p[i],pol,m)<<endl;
           if(inside_convex(p[i],pol,m))
             ans++;
       }
       cout<<n-ans<<endl;
    }
}      
                  
