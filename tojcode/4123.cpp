#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int mod=1e9+7;
struct job
{
    int p,r;
}a[110000];
bool cmp(job  aa,job bb)
{
    return aa.r<bb.r;
}
priority_queue<int,vector<int>,greater<int> > q;
int n;
int main()
{
       while(~scanf("%d",&n))
       {
           while(!q.empty())q.pop();
           for(int i=0;i<n;i++)
           {
              scanf("%d%d",&a[i].p,&a[i].r);
           }
           sort(a,a+n,cmp);
           int ans=0;
           int cnt=0;
           int tim=0;
           int tmp;
           for(tim=0;tim<=10000;tim++)
           {
               while(cnt<n&&a[cnt].r==tim)
               {
                   q.push(a[cnt].p);
                   cnt++;
               }
               while(!q.empty())
               {
                   tmp=q.top();
                   q.pop();

                   if(tmp==0)
                   {
                       ans=ans+tim;

                       if(ans>=mod)ans-=mod;
                       continue;
                   }
                   else
                   {
                       tmp--;

                           q.push(tmp);


                       break;
                   }
               }
           }
           while(!q.empty())
           {

                tmp=q.top();
                   q.pop();
                ans=ans+tim+tmp;
                if(ans>=mod)
                    ans-=mod;
                tim+=tmp;
                if(tim>=mod)
                    tim-=mod;

           }
           printf("%d\n",ans);
       }
}
