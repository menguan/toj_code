#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int les;
int a[110];
int A,B;
int n;
int tmp;
int ans;
int get(int p)
{
    int h=1010101010;
    for(int i=0;i<n;i++)
    {
        h=min(h,abs(p-a[i]));
    }
    return h;
}
void bfs(int st,int dis)
{
    queue<int> q;
    q.push(st);
    int u,v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        //cout<<u<<" "<<get(u)<<" "<<tmp<<endl;
        if(u<A||u>B) continue;
        if(u%2==0&&dis!=1)
        {
            q.push(u+1);
            q.push(u-1);
            continue;
        }
        if(u%2==1&&dis==1)
        {
              q.push(u+1);
            q.push(u-1);
            continue;
        }
        int tt=u+dis;
        if(tt<=B&&tt>=A)
        if((v=get(tt))>tmp)
        {
            tmp=v;
            ans=tt;
            q.push(tt);
        }
        tt=u-dis;
        if(tt<=B&&tt>=A)
        if((v=get(tt))>tmp)
        {
            tmp=v;
            ans=tt;
            q.push(tt);
        }
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
          sort(a,a+n);

        scanf("%d%d",&A,&B);if(A%2==0)A++;
        if(B%2==0)B--;

        ans=0;
        int tmp=-1;
       int hh;
        int aa=1010101010;
        int bb=aa;
        for(int i=0;i<n;i++)
        {
            if(i)
            {
              hh=(a[i]-a[i-1])/2;
              if(hh%2==0)hh--;
              if(hh>tmp&&a[i]-hh>=A&&a[i]-hh<=B)
                    {
                        ans=a[i]-hh;
                        tmp=hh;
                    }
               if(hh>tmp&&a[i-1]+hh>=A&&a[i-1]+hh<=B)
                    {
                        ans=a[i-1]+hh;
                        tmp=hh;
                    }
            }
            aa=min(aa,abs(a[i]-A));
            bb=min(bb,abs(a[i]-B));

        }if(aa>tmp)
            {
                ans=A;
                tmp=aa;
            }
            if(bb>tmp)
            {
                ans=B;
                tmp=bb;
            }
        printf("%d\n",ans);
    }
}

