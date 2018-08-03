#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct point
{
       double x;double y;
}p[200],cir;
double cross(point a,point b,point c)
{
     return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
double dis(point a,point b)
{
       return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main()
{
    double r;int n;
    int cnt;
    while(cin>>cir.x>>cir.y>>r&&r>0)//The end of the input is signalled by a line with a negative radius
    {
        cnt=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
             point temp;
             cin>>temp.x>>temp.y;
             if(dis(temp,cir)<=r*r)
             {
                p[cnt++]=temp;
             }
        }
        int ans=0;
        for(int i=0;i<cnt;i++)
        {
            int cou=1;
            for(int j=0;j<cnt;j++)
            {
                if(i==j)  continue;
                if(cross(cir,p[i],p[j])<=0)
                    cou++;
            }
            ans=max(ans,cou);
        }
        cout<<ans<<endl;
    }
}        
                                                                       
                               
  
